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

#include "Flug.h"
#include "Flugplan.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    if(argc != 1)
        cerr << "Y u throwin arguments at mey, yo dwag!" << endl;
    
    
    
    Flugplan flugplan();
    
    //vector<Flug*> found =  flugplan.sucheFlug("start1", "lande3");
    
    //for(int i = 0; i < found.size(); i++)
     //   cout << found.at(i)->getFlugnummer() << endl;
    return 0;
}

