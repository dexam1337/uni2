/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.h
 * Author: sebastian
 *
 * Created on May 21, 2017, 12:20 AM
 */

#ifndef TRAP_H
#define TRAP_H

#include "Floor.h"

class Trap : public Floor {
public:
    Trap(Item* item, int damage);
    Trap(const Trap& orig);
    virtual ~Trap();
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    char print() override;
    char save() override;
    void setActivated(bool activated);
private:
    int m_damage; //negative Werte für Schaden, positiv für Heilung
    bool m_activated;

};

#endif /* TRAP_H */

