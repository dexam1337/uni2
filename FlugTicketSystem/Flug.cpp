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
    string startOrt, landeOrt, zeile;
    int startZeit, landeZeit;
    getline(inputstream, zeile);
    stringstream ss(zeile);
    ss >> flug.m_flugnummer >> flug.m_kapazitaet;
    flug.m_freiePlaetze = flug.m_kapazitaet;
    while (ss.good()) {
        ss >> startOrt >> startZeit >> landeOrt >> landeZeit;
        flug.m_startOrt.push_back(startOrt);
        flug.m_startZeiten.push_back(startZeit);
        flug.m_landeOrt.push_back(landeOrt);
        flug.m_landeZeiten.push_back(landeZeit);
    }
    return inputstream;
}

std::ostream& operator<<(std::ostream& outputstream, const Flug& flug) {
    vector<int> startZeiten, landeZeiten;
    vector<string> startOrte, landeOrte;
    startOrte = flug.getStartOrt();
    landeOrte = flug.getLandeOrt();
    startZeiten = flug.getStartZeiten();
    landeZeiten = flug.getStartZeiten();
    outputstream << "Flugnummer: " << flug.getFlugnummer() << " Kapazität: " << flug.getKapazitaet() << " Freie Plätze: " << flug.getFreiePlaetze() << endl;
    for(int i = 0; i < startZeiten.size(); i++){
        cout << endl << "Abflug: " << startOrte.at(i) << " um " << startZeiten.at(i)<< endl;
    cout << "Landet: " << landeOrte.at(i) << " um " << landeZeiten.at(i) << endl << endl;
    }
    cout << endl;
    return outputstream;
}

int Flug::getFlugnummer() const {
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

inline bool Flug::operator<(const Flug& rechts) const {
    return (m_flugnummer < rechts.m_flugnummer);
}

inline bool Flug::operator>(const Flug& rechts) const {
    return (*this < rechts);
}
/*
ostream& operator<<(ostream& outStream, const Flug& flug) {
    outStream << "Flugnr: " << flug.getFlugnummer() << "\n";
    for (int i = 0; i < flug.getStartZ().size(); i++) {
        outStream << "Startet in " << flug.getStartO().at(i) << " um " << flug.getStartZ().at(i) << "\n";
        outStream << "Landet in " << flug.getLandeO().at(i) << " um " << flug.getLandeZ().at(i) << "\n";
    }
    outStream << "Der Flug hat eine Kapazität von: " << flug.getKapazitaet() << " mit " << flug.getFreiePlaetze() << " freien Plätzen" << endl;
    return outStream;
}
 */