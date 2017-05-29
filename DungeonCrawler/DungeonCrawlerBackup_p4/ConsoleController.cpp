/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.cpp
 * Author: sebastian
 * 
 * Created on 12. Mai 2017, 00:07
 */

#include "ConsoleController.h"

ConsoleController::ConsoleController(Character* character) : Controller(character) {
}

/*
ConsoleController::ConsoleController(const ConsoleController& orig) {
}*/

ConsoleController::~ConsoleController() {
}

int ConsoleController::move() {
    int returnvalue;
    cout << "\n Wohin möchten sie laufen?\n";
    cin >> returnvalue;
    cin.clear();
    if (returnvalue <= 9 && returnvalue >= 0) {
        return returnvalue;
    } else {
        cout << "\nFehler bei der Eingabe!" << endl;
        return -1;
    }
    return -1;
}