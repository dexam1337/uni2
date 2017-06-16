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

using namespace std;

class Flug {
public:
    Flug(int kapazitaet);
    Flug(const Flug& orig);
    virtual ~Flug();

    friend istream& operator>>(istream& inputstream, Flug& flug);
    friend ostream& operator<<(ostream& inputstream, const Flug& flug);
    const int getFlugnummer();
    int hasStart(const string startOrt);
    int hasStopAfter(const string landeOrt, const int pos);
    void addSubFlight(const string startOrt, const string landeOrt);
    bool operator<(const Flug& rechts) const;
    bool operator>(const Flug& rechts) const;
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

