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

#include "Flugplan.h"

Flugplan::Flugplan() {
    
    
}

Flugplan::Flugplan(const Flugplan& orig) {
}

Flugplan::~Flugplan() {
    map<int, Flug*>::iterator it;
    for(it = m_fluege.begin(); it < m_fluege.end(); it++)
        delete (*it);
    
    m_fluege.clear();
}

void Flugplan::ladeFluege(const string dateiPfad){
    Flug* flug = new Flug(100);
    flug->addSubFlight("start1", "lande1");
    m_fluege.insert(flug);
}

Flug* Flugplan::sucheFlug(const int flugnummer){
    return m_fluege[flugnummer];
}

vector<Flug*> Flugplan::sucheFlug(const string startOrt, const string landeOrt){
    vector<Flug*> foundFluege;
    vector<Flug*>::iterator it;
    for(it = m_fluege.begin(); it < m_fluege.end(); it++)
        if((*it)->hasStart(startOrt) != -1)
            foundFluege.push_back(*it);
    
    for(it = foundFluege.begin(); it < foundFluege.end(); it++){
        if((*it)->hasStopAfter(landeOrt, (*it)->hasStart(startOrt)) == -1)
            foundFluege.erase(it);
    }
    return foundFluege;
}