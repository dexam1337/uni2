/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flug.h
 * Author: sebastian
 *
 * Created on 7. Juni 2017, 23:46
 */

#ifndef FLUG_H
#define FLUG_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class Flug {
public:
    Flug(int kapazitaet);
    Flug(const Flug& orig);
    virtual ~Flug();

    friend istream& operator>>(istream& inputstream, Flug& flug); //Aus und eingeabeoperatoren
    friend ostream& operator<<(ostream& outputstream, const Flug& flug);
    int getFlugnummer() const;
    int hasStart(const string startOrt); //sucht start und gibt position an
    int hasStopAfter(const string landeOrt, const int pos); //sucht ob nach start egewünschte landeort vorhanden
    void addSubFlight(const string startOrt, const string landeOrt); //fuegt hop ein
    inline bool operator<(const Flug& rechts) const; // vergleichsoperatoren 
    inline bool operator>(const Flug& rechts) const;

    int getFreiePlaetze() const {
        return m_freiePlaetze;
    }

    int getKapazitaet() const {
        return m_kapazitaet;
    }

    vector<string> getLandeOrt() const {
        return m_landeOrt;
    }

    vector<int> getLandeZeiten() const {
        return m_landeZeiten;
    }

    vector<string> getStartOrt() const {
        return m_startOrt;
    }

    vector<int> getStartZeiten() const {
        return m_startZeiten;
    }

    
private:

    int m_flugnummer;
    vector<int> m_startZeiten;
    vector<int> m_landeZeiten;
    vector<string> m_startOrt;
    vector<string> m_landeOrt;
    int m_kapazitaet;
    int m_freiePlaetze;
    static int counter;
};

#endif /* FLUG_H */

