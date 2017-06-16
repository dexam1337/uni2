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
Kunde::Kunde(string name, string tel, string iban, string bic, string username, string pwd) {
    m_name = name;
    m_tel = tel;
    m_iban = iban;
    m_bic = bic;
    m_username = username;
    m_pwd = pwd;
}

Kunde::Kunde(const Kunde& orig) {
    (*this) = orig;
}

Kunde::~Kunde() {
    vector<Buchung*>::iterator it;
    for(it = m_buchungen.begin(); it < m_buchungen.end(); it++)
        delete (*it);
    m_buchungen.clear();
}

bool Kunde::login(string pwd) {
    if (pwd == m_pwd){
        std::cout << "Login erfolgreich" << std::endl;
        return true;
    }
    else{
        std::cout <<"Falsches Password" << std::endl;
        return false;
    }
}

bool Kunde::buche(Buchung* buchung){
    //Hier zahlungsmechanismus einfuegen
    m_buchungen.push_back(buchung);
    return true;
}

inline bool Kunde::operator>(const Kunde& rigth) const{
    return (m_username > rigth.m_username);
} 

inline bool Kunde::operator<(const Kunde& rigth) const{
    return (*this > rigth);
}

ostream& operator<<(ostream& outStream, const Kunde& kunde){
    
    outStream << kunde.m_name << endl << "Telefonnummer: " << kunde.m_tel << endl << "Iban: " << kunde.m_iban << " Bic: " << kunde.m_bic << endl;
}