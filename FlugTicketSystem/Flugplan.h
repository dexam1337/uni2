/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flugplan.h
 * Author: sebastian
 *
 * Created on 7. Juni 2017, 23:45
 */

#ifndef FLUGPLAN_H
#define FLUGPLAN_H
#include "Flug.h"

#include <map>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;
class Flugplan {
public:
    Flugplan();
    Flugplan(const Flugplan& orig);
    virtual ~Flugplan();
    
    void ladeFluege(const string dateiPfad); //laed fluege aus datei
    Flug* sucheFlug(const int flugnummer); //sucht flug über nummer 
    vector<Flug*> sucheFlug(const string startOrt, const string landeOrt); //gibt alle fluege die kriterien erfüllen 
    friend std::ostream& operator<<(std::ostream& os, const Flugplan& obj) ;

private:
    map<int, Flug*> m_fluege;

};

#endif /* FLUGPLAN_H */

