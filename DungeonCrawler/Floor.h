/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.h
 * Author: sebastian
 *
 * Created on 4. Mai 2017, 16:07
 */

#ifndef FLOOR_H
#define FLOOR_H

#include "Tile.h"
#include "Item.h"

class Floor : public Tile {
public:
    Floor(Character* c, Item* item);
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    char print() override;

private:
    Item* m_item;

};

#endif /* FLOOR_H */

