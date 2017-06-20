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


}

Flugplan::Flugplan(const Flugplan& orig) {
}

Flugplan::~Flugplan() {
    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++)
       delete (it->second);

    m_fluege.clear();
}

void Flugplan::ladeFluege(const string dateiPfad) {
    
    std::srand(std::time(0));
    for(int i = 0; i < 100; i++){
    Flug* flug = new Flug(std::rand());
    flug->addSubFlight("start" , "lande" );
    m_fluege[flug->getFlugnummer()] = flug;}
}

Flug* Flugplan::sucheFlug(const int flugnummer) {
    return m_fluege[flugnummer];
}

vector<Flug*> Flugplan::sucheFlug(const string startOrt, const string landeOrt) {

}

void Flugplan::alleFluegeAnzeigen() const{
    
    for(auto it = m_fluege.begin(); it != m_fluege.end(); it++)
        cout << *(it->second) << endl;
   
}