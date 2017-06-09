/*
 * Title.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "Tile.h"

Tile::Tile(/*Typ typ,*/ Character* character) {
    //m_typ = typ;
    m_character = character;
}

/*
Tile::Typ Tile::getTyp() {
        return m_typ;
}*/

Tile::~Tile() {
    m_character = nullptr;
}

Character* Tile::getCharacter() {
    return m_character;
}

bool Tile::hasCharacter() {
    if (m_character == nullptr)
        return false;
    return true;
}

void Tile::setCharacter(Character* character) {
    m_character = character;
}

void Tile::onLeave(Tile* toTile) {
    toTile->onEnter(m_character, this);
}

void Tile::onEnter(Character* c, Tile* fromTile) {
    if (hasCharacter() == true) {
        fromTile->onEnter(c, this);
    } else {
        fromTile->setCharacter(nullptr);
        m_character = c;
    }
}

char Tile::print() {/*
	if (hasCharacter()) {
		return m_character->getSymbol();
	} else if (m_typ == Tile::Floor) {
		return '.';
	} else {
		return '#';
	}*/
    return '^';
}

bool Tile::isTransparent(){
    return true;
}

char Tile::save() {
    return this->print();
}