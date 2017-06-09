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

class AttackController : public Controller{
public:
    AttackController(Character* character);
    virtual ~AttackController();
    int move() override;
    std::string getControllerName() override;
    
private:
    AttackController(const AttackController& orig);

};

#endif /* ATTACKCONTROLLER_H */

