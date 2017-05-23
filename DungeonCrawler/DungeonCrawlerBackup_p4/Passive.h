/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.h
 * Author: sebastian
 *
 * Created on 11. Mai 2017, 22:55
 */

#ifndef PASSIVE_H
#define PASSIVE_H

#include "Tile.h"

class Passive : public Tile{
public:
    Passive();
    //Passive(const Passive& orig);
    virtual ~Passive();
    virtual void setStatus(bool status);
    virtual void use(); //tooglet Objekt
    virtual bool getStatus();
private:

    bool m_status;
};

#endif /* PASSIVE_H */

