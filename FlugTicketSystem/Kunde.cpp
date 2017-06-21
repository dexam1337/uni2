/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kunde.cpp
 * Author: sebastian
 * 
 * Created on 9. Juni 2017, 23:09
 */

#include "Kunde.h"


Kunde::Kunde(){
    
}
Kunde::Kunde(string name, string tel, string iban, string bic, string username, string pwd) { //Konstruktor des Kunden
    m_name = name; //speichere übergebenen namensstring in memberattribut
    m_tel = tel; //speichere übergebene telefonnummer in memeberattriubt
    m_iban = iban; //speichere übergebene iban in memberattribut
    m_bic = bic; //speichere übergebene bic in memberattribut
    m_username = username; //speichere übergebenen username in memberattribut
    m_pwd = pwd; //speichere übergebenes passwort in memberattribut
}

Kunde::Kunde(const Kunde& orig) { //kopierkonstruktor 
    (*this) = orig; //dereferenziert den this pointer des neuen objektes und benutzt zuweisungsoperator;
}

Kunde::~Kunde() { //destruktor
    //vector<Buchung*>::iterator it;
    for(auto it = m_buchungen.begin(); it < m_buchungen.end(); it++) //iterator über alle elemente des arrays
        delete (*it); //lösche jede buchung in m_buchungen
    m_buchungen.clear(); //lösche pointer in m_buchungen
}

bool Kunde::login(string pwd) { //login funktion zum überprüfen des passwortes
    if (pwd == m_pwd){ //wenn übergebenes passwort gleich dem gespeicherten
        std::cout << "Login erfolgreich" << std::endl; //meldung über erfolg
        return true; //gib erfolg zurück
    }
    else{ //ansonsten
        std::cout <<"Falsches Password" << std::endl; //meldung über falsches Passwort
        return false; //gibt fehler zurück
    }
}

bool Kunde::buche(Buchung* buchung){ //buche speichert die buchungen die der Kunde tätigen möchte
    //Hier zahlungsmechanismus einfuegen
    m_buchungen.push_back(buchung); //speichere übergebene buchung 
    return true; //melde das kauf erfolgreich war
}

inline bool Kunde::operator>(const Kunde& rigth) const{ //vergleichsoperator
    return (m_username > rigth.m_username); //sortierung erfolg nach username
} 

inline bool Kunde::operator<(const Kunde& rigth) const{ //anderer vergleichsoperator
    return (*this > rigth); //gegenteil zu vorherigem vergleichsoperator
}

ostream& operator<<(ostream& outStream, const Kunde& kunde){ //outputstream von kunde
    
    outStream << kunde.m_name << endl << "Telefonnummer: " << kunde.m_tel << endl << "Iban: " << kunde.m_iban << " Bic: " << kunde.m_bic << endl; //gib wichtige informationen aus, aber nicht mehr als erlaubt
    return outStream; //gibt outputstream zurück (operatorkonvention)
}