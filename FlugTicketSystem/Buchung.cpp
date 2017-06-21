/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buchung.cpp
 * Author: sebastian
 * 
 * Created on 9. Juni 2017, 23:08
 */

#include "Buchung.h"
#include "Kunde.h"

int Buchung::counter = 0;

Buchung::Buchung(Kunde& kunde) : m_kunde(kunde){
    m_buchungsnummer = counter;
    counter++;
}

Buchung::Buchung(const Buchung& orig) : m_kunde(orig.m_kunde){
    m_buchungsnummer = orig.m_buchungsnummer;
    m_tickets = orig.m_tickets;
}

Buchung::~Buchung() {
}

float Buchung::getPreis(){
    float preis = 0;
    for(auto it = m_tickets.begin(); it != m_tickets.end(); it++)
        preis = preis + (*it).getPreis();
    return preis;
}