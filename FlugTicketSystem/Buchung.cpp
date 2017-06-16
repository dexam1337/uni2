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

//Buchung::Buchung(const Buchung& orig) {

//}

Buchung::~Buchung() {
}

