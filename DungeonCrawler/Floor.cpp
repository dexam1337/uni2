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

Floor::~Floor() {
    delete m_item;
    m_item = nullptr;
}

void Floor::onLeave(Tile* toTile) {
    toTile->onEnter(Tile::getCharacter(), this);
}

void Floor::onEnter(Character* c, Tile* fromTile) {
    if (hasCharacter() == false) {
        setCharacter(c);
        fromTile->setCharacter(nullptr);
        if (m_item != nullptr) {
            c->addItem(m_item);
            m_item = nullptr;
        }
    } else if(getCharacter() != c){ //Falls man an einer wand oder schalter steht wird man wieder auf sein eigenes Feld geschickt, und greift sich sonst selbst an
        if (!(getCharacter()->hit(c->getStrength()))) {
            c->hit(getCharacter()->getStrength());
            c->showInfo();
            getCharacter()->showInfo();  
            if(c->hit(0))
                fromTile->setCharacter(nullptr);//Character außerhalb des Feldes bewegen
        } else {
            setCharacter(nullptr);
            c->showInfo();
        }
    }
    else
        ;

}

char Floor::print() {
    if (Tile::hasCharacter() == true)
        return Tile::getCharacter()->getSymbol();
    else if (m_item != nullptr)
        return '*';
    return '.';
}

char Floor::save(){
    return '.';
}

Item* Floor::getItem() {
    return m_item;
}

void Floor::setItem(Item* item) {
    m_item = item;
}

bool Floor::canBeEntered(){
    if(Tile::hasCharacter() == true)
        return false;
    else 
        return true;
}