/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.h
 * Author: sebastian
 *
 * Created on 8. Juni 2017, 13:25
 */

#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "Controller.h"
#include "DungeonMap.h"

class AttackController : public Controller{
public:
    AttackController(Character* character, DungeonMap* map);
    virtual ~AttackController();
    int move() override;
    std::string getControllerName() override;
    
private:
    Position seesCharacter();
    AttackController(const AttackController& orig);
    DungeonMap* m_map;
    vector<Position> m_lastPath;
};

#endif /* ATTACKCONTROLLER_H */

