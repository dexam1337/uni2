/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: sebastian
 *
 * Created on 12. Mai 2017, 00:03
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
class Character;

class Controller {

public:
    Controller(Character* character);
    Controller(const Controller& orig);
    virtual ~Controller();
    virtual int move() = 0;
    Character* getCharacter();
    virtual std::string getControllerName() = 0;
private:
    Character* m_character;
};

#endif /* CONTROLLER_H */

