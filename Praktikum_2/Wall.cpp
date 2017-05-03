/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Wall.h"

void onLeave(Tile* toTile) override
{
    toTile->onEnter(m_character, this);
    m_character = nullptr;

}

void onEnter(Character* c, Tile* fromTile) override
{

}

char print() override
{

}