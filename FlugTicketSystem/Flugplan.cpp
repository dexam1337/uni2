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

#include "Flugplan.h"

Flugplan::Flugplan() {
    Flug* flug = new Flug(20, 100);
    flug->addSubFlight("start1", "lande1");
    m_fluege.push_back(flug);
    
}

Flugplan::Flugplan(const Flugplan& orig) {
}

Flugplan::~Flugplan() {
    vector<Flug*>::iterator it;
    for(it = m_fluege.begin(); it < m_fluege.end(); it++)
        delete (*it);
    
    m_fluege.clear();
}

void Flugplan::ladeFluege(const string dateiPfad){
    
}

Flug* Flugplan::sucheFlug(const int flugnummer){
    vector<Flug*>::iterator it;
    for(it = m_fluege.begin(); it < m_fluege.end(); it++)
        if((*it)->getFlugnummer() == flugnummer)
            return *it;
    return nullptr;
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