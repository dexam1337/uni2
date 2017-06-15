/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.cpp
 * Author: sebastian
 * 
 * Created on 8. Juni 2017, 13:25
 */


#include "AttackController.h"
#include "DungeonMap.h"

AttackController::AttackController(Character* character, DungeonMap* map) : Controller(character) {
    m_map = map;
}

//AttackController::AttackController(const AttackController& orig) {
//}

AttackController::~AttackController() {
}

std::string AttackController::getControllerName() {
    return "AttackController";
}

int AttackController::move() {
    vector<Position> newPath;
    Position foundCharacter = seesCharacter();
    if (foundCharacter != Position(-1, -1))
        newPath = m_map->getPathTo(Position(18,18),Position(18,10));//m_map->findCharacter(dynamic_cast<Character*> (this)), foundCharacter);

    if (newPath.size() != 0)
        m_lastPath = newPath;

    if (m_lastPath.size() == 0)
        return 5;

    Position dp = m_map->findCharacter(dynamic_cast<Character*> (this)) - m_lastPath.at(0);
    m_lastPath.erase(m_lastPath.begin());

    if (dp.height == 1 && dp.width == -1)
        return 1;
    else if (dp.height == 0 && dp.width == -1)
        return 2;
    else if (dp.height == -1 && dp.width == -1)
        return 3;
    else if (dp.height == 1 && dp.width == 0)
        return 4;
    else if (dp.height == 0 && dp.width == 0)
        return 5;
    else if (dp.height == -1 && dp.width == 0)
        return 6;
    else if (dp.height == 1 && dp.width == 1)
        return 7;
    else if (dp.height == 0 && dp.width == 1)
        return 8;
    else if (dp.height == -1 && dp.width == 1)
        return 9;
    else{
        cerr<<"alter Pfad ungueltig geworden.";
        m_lastPath.clear();
        return 5;
    }



}

Position AttackController::seesCharacter() {
    return Position(18,1);
}