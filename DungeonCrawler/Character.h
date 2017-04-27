/*
 * Character.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character{
private:
    char m_symbol;

public:
    Character(char symbol);
    char getSymbol();
    int move();
};



#endif /* CHARACTER_H_ */
