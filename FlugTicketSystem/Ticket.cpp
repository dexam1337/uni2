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
    m_preis = preis; //Übernehme übergebenen Preis in member attribut
    m_ticketnummer = counter; //Übernehme aktuelle Ticketnummer 
    counter++; //zähle Ticketnummercounter hoch, für nächstes Ticket
    m_klasse = klasse; //speichere übergebene Reiseklasse des Tickets in member attribut
}

Ticket::Ticket(const Ticket& orig) { //kopierkonstruktor
    m_preis = orig.m_preis; //Kopiere preis des Orginalen objekts
    m_ticketnummer = orig.m_ticketnummer; //kopiere Ticketnummer des orginalen, da ticket "kopiert" wurde ist das zulässig
    m_klasse = orig.m_klasse; //kopiere reiseklasse des orginalen objektes
}

Ticket::~Ticket() { //generischer destruktor da keine Pointer in klasse vorhanden
}

inline bool Ticket::operator>(const Ticket& rigth) const { //vergleichsoperator
    return m_ticketnummer > rigth.m_ticketnummer; //soriterung der tickets erfolg nach ticketnummer
}

inline bool Ticket::operator<(const Ticket& rigth) const { //anderer vergleichsoperator
    return (*this > rigth); //ist das gegenteil des oben definierten operators
}