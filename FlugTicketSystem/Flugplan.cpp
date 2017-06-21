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

    ifstream save;
    save.open(dateiPfad);
    if (save.good() == false) {
        cerr << "Datei konnte nicht geöffnet werden!" << endl;
        return;
    }
    
    while(save.good()){
        Flug* flug = new Flug(0);
        save >> *flug;
        m_fluege[flug->getFlugnummer()] = flug;
    }
}


Flug* Flugplan::sucheFlug(const int flugnummer) {
    return m_fluege[flugnummer];
}

vector<Flug*> Flugplan::sucheFlug(const string startOrt, const string landeOrt) {
    vector<Flug*> gefundene;
    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++) {
        if ((*it).second->hasStopAfter(landeOrt, (*it).second->hasStart(startOrt)) != -1)
            gefundene.push_back((*it).second);
    }
    return gefundene;
}

void Flugplan::alleFluegeAnzeigen() const {

    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++)
        cout << *(it->second) << endl;

}