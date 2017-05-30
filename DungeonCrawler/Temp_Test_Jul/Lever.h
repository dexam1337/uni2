/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.h
 * Author: sebastian
 *
 * Created on May 21, 2017, 12:12 AM
 */

#ifndef LEVER_H
#define LEVER_H

#include "Active.h"

class Lever : public Active {
public:
    Lever(Passive* passive);
    //Lever(const Lever& orig);
    ~Lever();
    char print();
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);
private:

};

#endif /* LEVER_H */

