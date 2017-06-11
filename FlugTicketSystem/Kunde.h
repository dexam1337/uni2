/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kunde.h
 * Author: sebastian
 *
 * Created on 9. Juni 2017, 23:09
 */

#ifndef KUNDE_H
#define KUNDE_H

#include <vector>
#include <string>

class Buchung; //forwaddeclaration

using namespace std;

class Kunde {
public:
    Kunde(string name, string tel, string iban, string bic, string username, string pwd);
    Kunde(const Kunde& orig);
    virtual ~Kunde();

    bool login(string username, string pwd);
    string getName() {
        return m_name;
    };
    string getTel() {
        return m_tel;
    };
    string getIban(){return m_iban;};
    string getBic(){return m_bic;};
    bool buche(Buchung* buchung);

private:

    string m_name;
    string m_tel;
    string m_iban;
    string m_bic;
    string m_username;
    string m_pwd;
    vector<Buchung*> m_buchungen;

};

#endif /* KUNDE_H */

