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
    counter++; //zaehle counter hoch
}

Flug::Flug(const Flug& orig) { //kopierkonstruktor
    (*this) = orig; //kopoiere auf eigene alle attribute vom orginalen flugobjekt
}

Flug::~Flug() { //destruktor
}

istream& operator>>(istream& inputstream, Flug& flug) { //eingabeoperator
    string startOrt, landeOrt, zeile; //deklariere strings für die verwendung in der funktion
    int startZeit, landeZeit; //deklariere integer für verwendung in funktion
    getline(inputstream, zeile); //lese eine zeile aus streamobjekt 
    stringstream ss(zeile); //erstelle stringstream aus der zeile
    ss >> flug.m_flugnummer >> flug.m_kapazitaet; //lese flugnummer und kapazität aus zeile
    flug.m_freiePlaetze = flug.m_kapazitaet; //setzte die anzahl der freien plätze auf kapaziät
    while (ss.good()) { //solange ende der zeile nicht erreicht
        ss >> startOrt >> startZeit >> landeOrt >> landeZeit; //lese startOrt, start zeit, landeOrt, landeZeit
        flug.m_startOrt.push_back(startOrt); //speichere startort in memberattribut
        flug.m_startZeiten.push_back(startZeit); //speichere Startzeit in memebrattribut
        flug.m_landeOrt.push_back(landeOrt); //speichere landeort in memebrattriubut
        flug.m_landeZeiten.push_back(landeZeit); //speichere landezeit in memberattribut
    }
    return inputstream; //gib eingabestream zurück (konvention)
}

std::ostream& operator<<(std::ostream& outputstream, const Flug& flug) { //ausgabeoperator
    vector<int> startZeiten, landeZeiten; //deklariere vektoren für verwendung in funktion
    vector<string> startOrte, landeOrte; //deklariere string verkotren für verwenung in funktion
    startOrte = flug.getStartOrt(); //hole startorte von auszugebenden flug
    landeOrte = flug.getLandeOrt(); //hole landeorte von auszugebenden flug
    startZeiten = flug.getStartZeiten(); //hole startzeiten von auszugebenden flug
    landeZeiten = flug.getStartZeiten(); //hole landezeiten von auszugebenden flug
    outputstream << "Flugnummer: " << flug.getFlugnummer() << " Kapazität: " << flug.getKapazitaet() << " Freie Plätze: " << flug.getFreiePlaetze() << endl; //schreibe infos über flug in streamobjekt
    for(int i = 0; i < startZeiten.size(); i++){ //für jedes element in den fluginfovektoren
        cout << endl << "Abflug: " << startOrte.at(i) << " um " << startZeiten.at(i)<< endl; //gib start ort und zeit in streamobjekt
    cout << "Landet: " << landeOrte.at(i) << " um " << landeZeiten.at(i) << endl << endl; //gib lande ort und zeit in streamobjekt
    }
    cout << endl; 
    return outputstream; //gib streamobjekt zurück (konvention)
}

int Flug::getFlugnummer() const { //gibt flugnummer zurück
    return m_flugnummer; //gib flugnummer zurpck
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