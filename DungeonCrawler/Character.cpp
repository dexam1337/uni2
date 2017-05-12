/*
 * Character.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(char symbol) {
    m_symbol = symbol;
    m_controller = ConsoleController();
}

Character::~Character(){
    delete m_controller;
    m_controller = nullptr;
}
char Character::getSymbol() {
    return m_symbol;
}

int Character::move() {
    if(m_controller == nullptr)
        return -1;
    return m_controller->move();
}

