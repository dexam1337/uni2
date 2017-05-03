/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.h
 * Author: stud
 *
 * Created on 3. Mai 2017, 12:50
 */

#ifndef FLOOR_H
#define FLOOR_H

#include "Tile.h"

class Floor : public Tile
{
private:
    
public:
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    char print() override;
};


#endif /* FLOOR_H */

