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

class Buchung { //Verknüpft tickets mit kunde
public:
    Buchung(Kunde& kunde);
    //Buchung(const Buchung& orig);
    virtual ~Buchung();
    Kunde& getKunde(){return m_kunde;}; //trivial?
    int getBuchungsnummer(){return m_buchungsnummer;};
    void setTickets(std::vector<Ticket> tickets){m_tickets = tickets;};
    std::vector<Ticket> getTickets(){return m_tickets;};
private:
    
    int m_buchungsnummer;
    std::vector<Ticket> m_tickets;
    Kunde& m_kunde;
    static int counter;
};

#endif /* BUCHUNG_H */

