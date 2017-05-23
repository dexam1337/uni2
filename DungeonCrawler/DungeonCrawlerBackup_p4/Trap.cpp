/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.cpp
 * Author: sebastian
 * 
 * Created on May 21, 2017, 12:20 AM
 */

#include "Trap.h"

Trap::Trap(Item* item, int damage) : Floor(nullptr, item) {
    m_damage = damage;
    m_activated = false;
}

/*
Trap::Trap(const Trap& orig) {
}*/

Trap::~Trap() {
}

void Trap::onLeave(Tile* toTile) {
    toTile->onEnter(Tile::getCharacter(), this);
}

void Trap::onEnter(Character* c, Tile* fromTile) {
    if (Tile::hasCharacter() == false) {
        Tile::setCharacter(c);
        fromTile->setCharacter(nullptr);
        if (m_activated == false) {
            c->hit(m_damage);
            m_activated = true;
        }
        if (Floor::getItem() != nullptr) {
            c->addItem(Floor::getItem());
            Floor::setItem(nullptr);
        }
    } else
        ;
}

char Trap::print() {
    if (Tile::hasCharacter() == true)
        return Tile::getCharacter()->getSymbol();
    else if (Floor::getItem() != nullptr)
        return Floor::getItem()->print();
    else if (m_activated == true)
        return 'T';
    return '.';
}

void Trap::setActivated(bool activated){
    m_activated = activated;
}