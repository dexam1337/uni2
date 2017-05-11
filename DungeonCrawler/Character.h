/*
 * Character.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ConsoleController.h"

class Character {
private:
	char m_symbol;
        ConsoleController* m_controller;
public:
	Character(char symbol);
	char getSymbol();
	int move();
};

#endif /* CHARACTER_H_ */
