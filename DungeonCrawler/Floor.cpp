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

Floor::Floor(Character* c, Item* item) : Tile(c) {
    m_item = item;
}

Floor::~Floor(){
    delete m_item;
    m_item = nullptr;
}
void Floor::onLeave(Tile* toTile) {
    toTile->onEnter(Tile::getCharacter(), this);
}

void Floor::onEnter(Character* c, Tile* fromTile) {
    if (Tile::hasCharacter() == false) {
        Tile::setCharacter(c);
        fromTile->setCharacter(nullptr);
        if(m_item != nullptr) {
            c->addItem(m_item);
            m_item = nullptr;
        }
    } else
        ;
}

char Floor::print() {
    if (Tile::hasCharacter() == true)
        return Tile::getCharacter()->getSymbol();
    else if(m_item != nullptr)
        return '*';
    return '.';
}

Item* Floor::getItem(){
    return m_item;
}

void Floor::setItem(Item* item){
    m_item = item;
}