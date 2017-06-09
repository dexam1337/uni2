/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buchung.h
 * Author: sebastian
 *
 * Created on 9. Juni 2017, 23:08
 */

#ifndef BUCHUNG_H
#define BUCHUNG_H

#include "Ticket.h"
#include "Kunde.h"

class Buchung {
public:
    Buchung();
    Buchung(const Buchung& orig);
    virtual ~Buchung();
private:
    
    int m_buchungsnummer;
    vector<Ticket> m_tickets;
    
};

#endif /* BUCHUNG_H */

