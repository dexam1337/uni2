/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ticket.h
 * Author: sebastian
 *
 * Created on 9. Juni 2017, 23:03
 */

#ifndef TICKET_H
#define TICKET_H

typedef enum {
    ECONOMY,
    BUISNESS,
    FIRSTCLASS
} Reiseklasse;

class Ticket {
public:
    Ticket(float preis, Reiseklasse klasse);
    Ticket(const Ticket& orig);
    virtual ~Ticket();

    float getPreis() {
        return m_preis;
    };

    int getTicketnummer() {
        return m_ticketnummer;
    };

    Reiseklasse getKlasse() {
        return m_klasse;
    };

    inline bool operator>(const Ticket& rigth) const;
    inline bool operator<(const Ticket& rigth) const;
private:

    unsigned int m_preis;
    int m_ticketnummer;
    Reiseklasse m_klasse;
    static int counter;
};

#endif /* TICKET_H */

