/*
 * Character.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ConsoleController.h"
#include "Item.h"
#include <vector>

class Character {
private:
    vector<Item*> m_items;
    int m_strength;
    int m_stamina;
    int m_hitpoints;
    string m_name;
    char m_symbol;
    Controller* m_controller;

public:

    int getMaxHP();
    Character(string name, char symbol, int strength, int stamina, Controller* controller);
    ~Character();
    char getSymbol();
    int move();
    void showInfo();
    void addItem(Item* item);
    int getStrength();
    int getStamina();
    bool hit(int damage); //gibt true zurück wenn hp < 0;
    bool heal(int damage);
    friend std::ostream& operator<<(std::ostream& outputstream, const Character& character);
};



#endif /* CHARACTER_H_ */
