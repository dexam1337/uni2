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
#include <vector>
class Kunde;

class Buchung {
public:
    Buchung(Kunde& kunde);
    //Buchung(const Buchung& orig);
    virtual ~Buchung();
    Kunde& getKunde(){return m_kunde;};
    int getBuchungsnummer(){return m_buchungsnummer;};
private:
    
    int m_buchungsnummer;
    std::vector<Ticket> m_tickets;
    Kunde& m_kunde;
    static int counter;
};

#endif /* BUCHUNG_H */

