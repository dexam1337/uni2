/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.cpp
 * Author: sebastian
 * 
 * Created on 11. Mai 2017, 23:28
 */

#include "Door.h"

Door::Door() : Passive() {
}

Door::Door(const Door& orig) {
}

Door::~Door() {
}

char Door::print() {
    if (this->hasCharacter())
        return this->getCharacter()->getSymbol();
    if (Passive::getStatus() == false)
        return 'X';
    else
        return '/';
}

void Door::onLeave(Tile* toTile) {
    toTile->onEnter(Tile::getCharacter(), this);
}

void Door::onEnter(Character* c, Tile* fromTile) {
    //cout << fromTile->getCharacter();
    if (this->getStatus() == false) {
        fromTile->onEnter(c, this);
        //cout << "Door is closed" << endl;
    } else {
        this->setCharacter(c);
        fromTile->setCharacter(nullptr);
    }
}

bool Door::isTransparent(){
    if(getStatus() == false)
        return false;
    else 
        return true;
}