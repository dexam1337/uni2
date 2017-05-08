/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.cpp
 * Author: sebastian
 * 
 * Created on 4. Mai 2017, 16:07
 */

#include "Floor.h"

Floor::Floor(Character* c) : Tile(c) {
    Tile::setCharacter(c);
}


void Tile::onLeave(Tile* toTile) {
    toTile->onEnter(m_character, this);
}

void Tile::onEnter(Character* c, Tile* fromTile) {
    if (Tile::hasCharacter() == false) {
        m_character = c;
        fromTile->setCharacter(nullptr);
    } else
        ;
}

char print() {
    if (Tile::hasCharacter() == true)
        return Tile::getCharacter()getSymbol();

    else
        return '.';
}