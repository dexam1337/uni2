/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CUI.cpp
 * Author: sebastian
 * 
 * Created on 7. Juni 2017, 23:45
 */



#include "CUI.h"


CUI::CUI() {
    m_kunden["Corship"] = Kunde("First Second", "APhoneNumer", "AIban", "ABic", "AUsername", "123");
}

CUI::CUI(const CUI& orig) {
}

CUI::~CUI() {
}

bool CUI::zeigeMenue() {
    int eingabe, flugnummer, nTickets;
    string username, pwd, name, tel, iban, bic;
    Kunde neuerKunde;
    cout << MENU << endl;
    cin >> eingabe;

    switch (eingabe) {
        case 1:
            cout << "Username und Password:" << endl;
            cin >> username >> pwd;
            login(username, pwd);
            return true;
        case 2:
            cout << endl << "Nutzername:";
            cin >> username;
            if((m_kunden.find(username) != m_kunden.end()) && m_kunden.begin() != m_kunden.end()){
                cerr << endl << "Nutzername schon vergeben!" << endl;
                return true;
            }

            cout << endl << "Vor und Nachname: ";
            cin.ignore(1);
            cin;
            getline(cin, name);

            cout << endl << "Telefonnummer: ";
            cin.ignore(1);
            cin;
            getline(cin, tel);

            cout << endl << "iban: ";
            cin.ignore(1);
            cin;
            getline(cin, iban);

            cout << endl << "Bic: ";
            cin.ignore(1);
            cin;
            getline(cin, bic);

            cout << endl << "Passwort: ";
            cin >> pwd;
            //getline(cin, pwd);

            m_kunden[username] = Kunde(name, tel, iban, bic, username, pwd);
            return true;

        case 3:
            cout << "Nutzername des Anzuzeigenden kunden:";
            //cin.ignore();
            cin >> username;
            cout << endl << endl << m_kunden[username] << endl;
            return true;
        case 4:
            break;

        case 5:
            break;

        default:

            break;
    }
    return false;
}

bool CUI::login(string username, string pwd) {
    if (m_kunden.find(username) != m_kunden.end())
        return m_kunden[username].login(pwd);
    else{
        cout << "Unbekannter nutzername" << std::endl;
        return false;
    }}