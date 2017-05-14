/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.h
 * Author: sebastian
 *
 * Created on 11. Mai 2017, 23:28
 */

#ifndef DOOR_H
#define DOOR_H

#include "Passive.h"

class Door : public Passive {
public:
    Door();
    Door(const Door& orig);
    ~Door();
    char print() override;

    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
private:

};

#endif /* DOOR_H */

