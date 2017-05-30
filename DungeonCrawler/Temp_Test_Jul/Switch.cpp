/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.cpp
 * Author: sebastian
 * 
 * Created on 11. Mai 2017, 23:28
 */

#include "Switch.h"

Switch::Switch(Passive* passive) : Active(passive) {
}

/*
Switch::Switch(const Switch& orig) {
}*/

Switch::~Switch() {
}

char Switch::print() {
    if (Active::getStatus() == false)
        return 's';
    else
        return 'S';
}

void Switch::onLeave(Tile* toTile) {
    //can't enter on first place;
}

void Switch::onEnter(Character* c, Tile* fromTile) {
    //here what to do when triggered
    if(Active::getStatus()==false)
        use();
    fromTile->onEnter(c, this);
}