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
}

char Character::getSymbol() {
    return m_symbol;
}

int Character::move() {
    return m_controller->move();
}

