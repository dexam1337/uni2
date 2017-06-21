/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sebastian
 *
 * Created on 7. Juni 2017, 23:33
 */

#include <cstdlib>
#include <iostream>

#include "CUI.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) { //einstiegspunkt des programms
    
    if(argc != 1)   
        cerr << "Y u throwin arguments at mey, yo dwag!" << endl; 
    
    CUI cui = CUI(); //Erstellen des CUI objektes
    while(cui.zeigeMenue()) //Solange die CUI nicht 0 für "terminieren" zurück gibt wiederhole
        ;
    
    return 0; 
}

