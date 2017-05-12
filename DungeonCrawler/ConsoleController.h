/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.h
 * Author: sebastian
 *
 * Created on 12. Mai 2017, 00:07
 */


#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "Controller.h"
#include <iostream>

using namespace std;

class ConsoleController : public Controller{
public:
    
    ConsoleController(Character* character);
    //ConsoleController(const ConsoleController& orig);
    ~ConsoleController();
    int move();
private:

};

#endif /* CONSOLECONTROLLER_H */

