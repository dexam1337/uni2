/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.h
 * Author: sebastian
 *
 * Created on 11. Mai 2017, 23:28
 */

#ifndef SWITCH_H
#define SWITCH_H

#include "Active.h"

class Switch : public Active {
public:
    Switch(Passive* passive);
    //Switch(const Switch& orig);
    ~Switch();
    char print();
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);
private:

};

#endif /* SWITCH_H */

