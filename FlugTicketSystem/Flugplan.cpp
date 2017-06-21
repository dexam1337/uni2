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

Flugplan::Flugplan() { //konstruktor für flugplan

    ladeFluege("fluege.txt");

}

Flugplan::Flugplan(const Flugplan& orig) { //kopierkonstruktor von flugplan
    (*this) = orig;
}

Flugplan::~Flugplan() { //destruktor von Flugplan
    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++) //forschelife mit iterator über alle elemente
        delete (it->second); //lösche jedes element das in der map GESPEICHERT ist

    m_fluege.clear(); //leere map
}

void Flugplan::ladeFluege(const string dateiPfad) { //lade fluege aus datei

    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++) //forschelife mit iterator über alle elemente
        delete (it->second); //lösche jedes element das in der map GESPEICHERT ist

    m_fluege.clear(); //leere map
    
    ifstream save; 
    save.open(dateiPfad); //öffne datei mit dem pfad dateipfad
    if (save.good() == false) { //sollte datei nicht geöffnet werden können
        return; //beende funktion
    }
    
    while(save.good()){ //solange datei noch nicht am ende
        Flug* flug = new Flug(0); //erstelle neuen flug
        save >> *flug; //nutze instream operator von FLug zum initialisieren des Fluges
        m_fluege[flug->getFlugnummer()] = flug; //speichere flug in map
    }
}


Flug* Flugplan::sucheFlug(const int flugnummer) { //suche flug über flugnummer
    return m_fluege[flugnummer]; 
}

vector<Flug*> Flugplan::sucheFlug(const string startOrt, const string landeOrt) { //sucht flug über start und landeort
    vector<Flug*> gefundene; //erstelle vektor der die pointer auf gefundene flüge speichert
    for (auto it = m_fluege.begin(); it != m_fluege.end(); it++) { //iterator über alle elemente
        if ((*it).second->hasStopAfter(landeOrt, (*it).second->hasStart(startOrt)) != -1) //wenn der stop nach dem start ist und der aktuelle flug beides hat, dann 
            gefundene.push_back((*it).second);      //speicher flug
    }
    return gefundene; //gibt alle gefundenen flüge zurück
}


std::ostream& operator<<(std::ostream& os, const Flugplan& obj) {
    for (auto it = obj.m_fluege.begin(); it != obj.m_fluege.end(); it++) //iterator über alle elemenete
        cout << *(it->second) << endl; 
        return os;
    }