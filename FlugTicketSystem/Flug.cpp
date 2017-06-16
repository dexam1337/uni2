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

int Flug::counter = 0;

Flug::Flug(int kapazitaet) : m_flugnummer(counter), m_kapazitaet(kapazitaet) {
    counter++;
}

Flug::Flug(const Flug& orig) {
}

Flug::~Flug() {
}

istream& operator>>(istream& inputstream, Flug& flug) {
    return inputstream;
}

std::ostream& operator<<(std::ostream& outputstream, const Flug& flug) {
    /* outputstream << "Flugnr: " << flug.m_flugnummer << " hat " << flug.m_kapazitaet << " Plaetze und insgesamt " << flug.m_startOrt.size() << " Abfluege.\n\n" ;
     iterator<string> it;
     for (it = flug.m_startOrt.begin(); it < flug.m_startOrt.end(); it++ ){
         outputstream << "Startet in " << flug.m_startOrt.at(it) << " um " << flug.m_startZeiten.at(it) << "\nLandet in " << flug.m_landeOrt.at(it) << " um " << flug.m_landeZeiten.at(it) << "\n" << endl;
     }*/
    return outputstream;
}

const int Flug::getFlugnummer() {
    return m_flugnummer;
}

int Flug::hasStart(const string startOrt) {
    vector<string>::iterator it;
    for (it = m_startOrt.begin(); it < m_startOrt.end(); it++)
        if ((*it) == startOrt)
            return it - m_startOrt.begin();
    return -1;
}

int Flug::hasStopAfter(const string landeOrt, const int pos) {
    vector<string>::iterator it;
    for (it = m_landeOrt.begin()+(pos - 1); it < m_landeOrt.end(); it++)
        if ((*it) == landeOrt)
            return it - m_landeOrt.begin();
    return -1;
}

void Flug::addSubFlight(const string startOrt, const string landeOrt) {
    m_startOrt.push_back(startOrt);
    m_landeOrt.push_back(landeOrt);
}

bool Flug::operator<(const Flug& rechts) const {
    return (m_flugnummer < rechts.m_flugnummer);
}

bool Flug::operator>(const Flug& rechts) const {
    return (*this < rechts);
}