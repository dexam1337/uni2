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
    if (Passive::getStatus() == false)
        return 'X';
    else
        return '/';
}

void Door::onLeave(Tile* toTile) {

}

void Door::onEnter(Character* c, Tile* fromTile) {
    if (Passive::getStatus() == false) {
        fromTile->onEnter(c, this);
        //cout << "Door is closed" << endl;
    }
    else{
        Passive::setCharacter(c);
        fromTile->setCharacter(nullptr);
    }
}