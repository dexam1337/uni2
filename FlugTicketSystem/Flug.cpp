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

int Flug::counter = 0; //statischer klassencounter für die flugnummer

Flug::Flug(int kapazitaet) : m_flugnummer(counter), m_kapazitaet(kapazitaet) { //konstruktor für Flug
    counter++; 
}

Flug::Flug(const Flug& orig) { //kopierkonstruktor
    (*this) = orig; 
}

Flug::~Flug() { //destruktor
}

istream& operator>>(istream& inputstream, Flug& flug) { //eingabeoperator
    string startOrt, landeOrt, zeile; 
    float startZeit, landeZeit; 
    getline(inputstream, zeile); //lese eine zeile aus streamobjekt 
    stringstream ss(zeile); //erstelle stringstream aus der zeile
    ss >> flug.m_flugnummer >> flug.m_kapazitaet; 
    flug.m_freiePlaetze = flug.m_kapazitaet; 
    while (ss.good()) { //solange ende der zeile nicht erreicht
        ss >> startOrt >> startZeit >> landeOrt >> landeZeit; 
        flug.m_startOrt.push_back(startOrt); 
        flug.m_startZeiten.push_back(startZeit); 
        flug.m_landeOrt.push_back(landeOrt); 
        flug.m_landeZeiten.push_back(landeZeit); 
    }
    return inputstream; //gib eingabestream zurück (konvention)
}

std::ostream& operator<<(std::ostream& outputstream, const Flug& flug) { //ausgabeoperator
    vector<float> startZeiten, landeZeiten; 
    vector<string> startOrte, landeOrte; 
    startOrte = flug.getStartOrt(); //hole informationen über flughafen von dem flugobjekt
    landeOrte = flug.getLandeOrt(); 
    startZeiten = flug.getStartZeiten(); 
    landeZeiten = flug.getStartZeiten(); 
    outputstream << "Flugnummer: " << flug.getFlugnummer() << " Kapazität: " << flug.getKapazitaet() << " Freie Plätze: " << flug.getFreiePlaetze() << endl; //schreibe infos über flug in streamobjekt
    for(int i = 0; i < startZeiten.size(); i++){ 
        cout << endl << "Abflug: " << startOrte.at(i) << " um " << startZeiten.at(i)<< endl; 
    cout << "Landet: " << landeOrte.at(i) << " um " << landeZeiten.at(i) << endl << endl; 
    }
    cout << endl; 
    return outputstream; //gib streamobjekt zurück (konvention)
}

int Flug::getFlugnummer() const { //gibt flugnummer zurück
    return m_flugnummer; 
}

int Flug::hasStart(const string startOrt) { //sucht einen string der einen flughafen bezeichnet und gibt zurück der wievielte stop das ist
    vector<string>::iterator it;
    for (it = m_startOrt.begin(); it < m_startOrt.end(); it++)
        if ((*it) == startOrt)
            return it - m_startOrt.begin();
    return -1;
}

int Flug::hasStopAfter(const string landeOrt, const int pos) { //schaut ob ein gegebener zeilflughafen nach dem startflughafen vorhanden ist.
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

void Flug::belegeTickets(int n){
    m_freiePlaetze = m_freiePlaetze-n;
}