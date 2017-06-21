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

int Ticket::counter = 0; //statisches Element der Klasse zur vergabe der ticketnummern

Ticket::Ticket(float preis, Reiseklasse klasse) { //Konstruktor des Tickets
    m_preis = preis; 
    m_ticketnummer = counter; 
    counter++; 
    m_klasse = klasse; 
}

Ticket::Ticket(const Ticket& orig) { //kopierkonstruktor
    m_preis = orig.m_preis; 
    m_ticketnummer = orig.m_ticketnummer;
    m_klasse = orig.m_klasse; 
}

Ticket::~Ticket() { 
}

inline bool Ticket::operator>(const Ticket& rigth) const { //vergleichsoperator
    return m_ticketnummer > rigth.m_ticketnummer; //soriterung der tickets erfolg nach ticketnummer
}

inline bool Ticket::operator<(const Ticket& rigth) const { 
    return (*this > rigth); 
}

