/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flugplan.cpp
 * Author: sebastian
 * 
 * Created on 7. Juni 2017, 23:45
 */

#include <map>
#include <algorithm>
#include <ostream>

#include "Flugplan.h"

Flugplan::Flugplan() {


}

Flugplan::Flugplan(const Flugplan& orig) {
}

Flugplan::~Flugplan() {
    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++)
       delete (it->second);

    m_fluege.clear();
}

void Flugplan::ladeFluege(const string dateiPfad) {
    Flug* flug = new Flug(100);
    flug->addSubFlight("start1", "lande1");
    m_fluege[flug->getFlugnummer()] = flug;
}

Flug* Flugplan::sucheFlug(const int flugnummer) {
    return m_fluege[flugnummer];
}

vector<Flug*> Flugplan::sucheFlug(const string startOrt, const string landeOrt) {

}

void Flugplan::alleFluegeAnzeigen() const{
   
}