/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.cpp
 * Author: sebastian
 * 
 * Created on 21. Mai 2017, 12:12 AM
 */

#include "Lever.h"

Lever::Lever(Passive* passive) : Active(passive) {
}

/*
Lever::Lever(const Lever& orig) {
}*/

Lever::~Lever() {
}

char Lever::print() {
    if (Active::getStatus() == false)
        return 'l';
    else
        return 'L';
}

void Lever::onLeave(Tile* toTile) {
    //can't enter on first place;
}

void Lever::onEnter(Character* c, Tile* fromTile) {
    //here what to do when triggered
    use();
    fromTile->onEnter(c, this);
}