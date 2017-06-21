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
    m_kunden["root"] = Kunde("Admin Account", "root@localhost.de", "000000", "000000", "root", "toor");
    m_loggedIn = "";
    m_flugplan = Flugplan();
    m_flugplan.ladeFluege("fluege");
}

CUI::CUI(const CUI& orig) {
}

CUI::~CUI() {
}

bool CUI::zeigeMenue() { //zeigt menu an

    if (m_loggedIn != "")
        cout << "Aktuell eingeloggt als: " << m_loggedIn << endl << endl;
    else
        cout << "Nicht eingeloggt." << endl << endl;
    int eingabe, flugnummer, nTickets;
    string username, pwd, name, tel, iban, bic, startOrt, landeOrt;
    vector<Flug*> found;
    cout << MENU << endl;
    cin >> eingabe;

    switch (eingabe) { //switch der die eingabe verarbeitet
        case 1: //eingloggen
            cout << "Username und Password:" << endl;
            cin >> username >> pwd;
            if (login(username, pwd))
                m_loggedIn = username;
            return true;
        case 2: //registrieren
            cout << endl << "Nutzername:";
            cin >> username;
            if ((m_kunden.find(username) != m_kunden.end()) && m_kunden.begin() != m_kunden.end()) {
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
            m_kunden[username] = Kunde(name, tel, iban, bic, username, pwd);
            m_loggedIn = username;
            return true;

        case 3: //kunde suchen
            cout << "Nutzername des Anzuzeigenden kunden:";
            //cin.ignore();
            cin >> username;
            cout << endl << endl << m_kunden[username] << endl;
            return true;
        case 4: //ausloggen
            m_loggedIn = "";
            return true;

        case 5: //flug per flugnummer suchen
            cout << "Flugnummer: " << endl;
            cin >> flugnummer;
            cout << endl << *(m_flugplan.sucheFlug(flugnummer)) << endl;
            return true;
            
        case 6: //flug per start und zielort suchen
            cout << endl << "Start und Zielort: " << endl;
            cin >> startOrt >> landeOrt;
            found = m_flugplan.sucheFlug(startOrt, landeOrt);
            for(auto it = found.begin(); it != found.end(); it++){
                cout << endl << *(*it) << endl;
            }
            return true;
            
        case 7: //ticket kaufen
            if(m_loggedIn != "")
            kaufeTicket();
            return true;
            
        case 8: //initalisieren
            m_flugplan.ladeFluege("fluege.txt");
            return true;
        case 9: //alle fluege anzeigen
            if(m_loggedIn == "root")
                m_flugplan.alleFluegeAnzeigen();
            return true;
        default:

            break;
    }
    return false;
}

bool CUI::login(string username, string pwd) { //überprüft ob login korrekt ist
    if (m_kunden.find(username) != m_kunden.end())
        return m_kunden[username].login(pwd);
    else {
        cout << "Unbekannter nutzername" << std::endl;
        return false;
    }
}

void CUI::kaufeTicket(){ //kauft ticket
    int n, flugnummer;
    vector<Ticket> tickets;
    cout << "Wie viele Ticket?:" << endl;
    cin >> n;
    cout << endl << "Flugnummer:" << endl;
    cin >> flugnummer;
    
    srand(time(0)); //preis wird noch zufällig generiert
    int preis = ((rand()+1)%100)+11;
    
    for(int i = 0; i < n; i++)
        tickets.push_back(Ticket(preis, Reiseklasse::ECONOMY));
    
    Buchung buchung(m_kunden[m_loggedIn]); //ordne buchung aktuell eingeloggtem kunden zu
    buchung.setTickets(tickets);
    
    for(int i = 0; i < tickets.size(); i++){ //zeige jetzt gekaufte tickets an
        cout << "Ticketnummer: " << tickets.at(i).getTicketnummer() << " Preis: " << tickets.at(i).getPreis() << endl;
    }
}