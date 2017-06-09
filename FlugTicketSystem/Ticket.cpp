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

Ticket::Ticket(float preis, int ticketnummer, Reiseklasse klasse) : m_klasse(klasse), m_preis(preis), m_ticketnummer(ticketnummer) {
}

Ticket::Ticket(const Ticket& orig) {
}

Ticket::~Ticket() {
}

