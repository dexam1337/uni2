/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.h
 * Author: sebastian
 *
 * Created on 4. Mai 2017, 16:35
 */

#ifndef WALL_H
#define WALL_H

#include "Tile.h"

class Wall : public Tile {
public:
    Wall();
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    char print() override;
private:

};

#endif /* WALL_H */

