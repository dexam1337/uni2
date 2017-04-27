/*
 * Title.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "Tile.h"

Tile::Tile(Typ typ, Character* character)
{
    m_typ = typ;
    m_character = character;
}

Tile::Typ Tile::getTyp()
{
    return m_typ;
}

Character* Tile::getCharacter()
{
    return m_character;
}

bool Tile::hasCharacter()
{
    if (m_character == nullptr)
        return false;
    return true;
}

void Tile::setCharacter(Character* character)
{
    m_character = character;
}

void Tile::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == false)
    {
        toTile->onEnter(m_character, this);
        m_character = nullptr;
    }
}

void Tile::onEnter(Character* c, Tile* fromTile)
{
    m_character = c;
}
