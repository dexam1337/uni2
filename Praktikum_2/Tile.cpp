/*
 * Title.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "Tile.h"

Tile::Tile(Character* character) : m_character()
{
    m_character = character;
}

Tile::Tile()
{
    m_character = nullptr;
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

virtual void Tile::setCharacter(Character* character)
{
    m_character = character;
}

char Tile::print()
{
    return " ";
}
