/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ticket.cpp
 * Author: sebastian
 * 
 * Created on 9. Juni 2017, 23:03
 */

#include "Ticket.h"

int Ticket::counter = 0;

Ticket::Ticket(float preis, Reiseklasse klasse) : m_klasse(klasse), m_preis(preis), m_ticketnummer(counter) {
    counter++;
}

Ticket::Ticket(const Ticket& orig) {
}

Ticket::~Ticket() {
}

inline bool Ticket::operator>(const Ticket& rigth) const {
    return m_ticketnummer > rigth.m_ticketnummer;
}

inline bool Ticket::operator<(const Ticket& rigth) const {
    return (*this > rigth);
}