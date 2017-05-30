/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.h
 * Author: sebastian
 *
 * Created on 11. Mai 2017, 22:55
 */

#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
#include "Tile.h"
class Passive;

class Active : public Tile {
public:
    //Active();
    Active(Passive* linked);
    //Active(const Active& orig);
    virtual ~Active();
    virtual void use(); //tooglet Objekt
    //virtual void setStatus(bool Status);
    virtual bool getStatus();
    void setLinked(Passive* linked);
private:

    vector<Passive*> m_linked; //to active Tile linked objekt, make it ** for multiple links
    bool m_status;

};

#endif /* ACTIVE_H */

