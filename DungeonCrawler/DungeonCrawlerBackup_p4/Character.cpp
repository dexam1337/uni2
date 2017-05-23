/*
 * Character.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "Character.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Character::Character(char symbol, int strength, int stamina) {
    m_symbol = symbol;
    m_controller = new ConsoleController(this);
    m_strength = strength;
    m_stamina = stamina;
    m_hitpoints = getMaxHP();
    m_name = "Character";
}*/

Character::Character(string name, char symbol, int strength, int stamina, Controller* controller) {
    m_name = name;
    m_symbol = symbol;
    m_controller = controller;
    m_strength = strength;
    m_stamina = stamina;
    m_hitpoints = getMaxHP();
}

Character::~Character() {
    delete m_controller;
    m_controller = nullptr;
    for(int i = 0; i < m_items.size(); i++)
        delete m_items.at(i);
    m_items.clear();
}

char Character::getSymbol() {
    return m_symbol;
}

int Character::move() {
    if (m_controller == nullptr)
        return -1;
    return m_controller->move();
}

int Character::getMaxHP() {
    return (20 + ( getStamina() * 5));
}

void Character::showInfo() {
    cout << m_name << ": \n" << "Hitpoints: " << m_hitpoints << " / " << getMaxHP() << "\n" <<
            "Strength: " << m_strength << " Stamina: " << m_stamina << "\n"<<
            "Items: " << m_items.size() << "\n" << endl;
}

void Character::addItem(Item* item) {
    m_items.push_back(item);
    //m_hitpoints = getMaxHP(); //Do items affect health?
}

int Character::getStrength() {
    int strength = m_strength;
    for (int i = 0; i < m_items.size(); i++) {
        strength = strength + m_items.at(i)->modifyStrength(m_strength); //Itemeffects don't accumulate
    }
    return strength;
}

int Character::getStamina() {
    int stamina = m_stamina;
    for (int i = 0; i < m_items.size(); i++) {
        stamina = stamina + m_items.at(i)->modifyStamina(m_stamina); //Itemeffects don't accumulate
    }
    return stamina;
}

bool Character::hit(int damage){
    m_hitpoints = m_hitpoints - damage;
    if(m_hitpoints <= 0)
        return true;
    else if(m_hitpoints > getMaxHP())
        m_hitpoints = getMaxHP();
    return false;
}

bool Character::heal(int damage){
    return hit(damage * -1);
}