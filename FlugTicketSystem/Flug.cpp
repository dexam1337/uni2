/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flug.cpp
 * Author: sebastian
 * 
 * Created on 7. Juni 2017, 23:46
 */

#include "Flug.h"

Flug::Flug(int flugnummer, int kapazitaet) : m_flugnummer(flugnummer), m_kapazitaet(kapazitaet) {
}

Flug::Flug(const Flug& orig) {
}

Flug::~Flug() {
}

istream& operator>>(istream& inputstream, Flug& flug){
    return inputstream;
}

ostream& operator<<(ostream& outputstream,const Flug& flug){
    /*outputstream << "Flugnr: " << flug.m_flugnummer << " hat " << flug.m_kapazitaet << " Plaetze und insgesamt " << flug.m_startOrt.size() << " Abfluege.\n\n" ;
    iterator<string> it;
    for (it = flug.m_startOrt.begin(); it < flug.m_startOrt.end(); it++ ){
        outputstream << "Startet in " << flug.m_startOrt.at(it) << " um " << flug.m_startZeiten.at(it) << "\nLandet in " << flug.m_landeOrt.at(it) << " um " << flug.m_landeZeiten.at(it) << "\n" << endl;
    }*/
    return outputstream;
}

const int Flug::getFlugnummer(){
    return m_flugnummer;
}

int Flug::hasStart(const string startOrt){
    
}