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
}

CUI::CUI(const CUI& orig) {
}

CUI::~CUI() {
}

bool CUI::zeigeMenue() {
    int eingabe, flugnummer, nTickets;
    string username, pwd;
    cout << MENU << endl;
    cin >> eingabe;

    switch (eingabe) {
        case 1:
            cout << "Username und Password:" << endl;
            cin >> username >> pwd;
            login(username, pwd);
            return true;
        case 2:

            break;

        case 3:
            break;

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