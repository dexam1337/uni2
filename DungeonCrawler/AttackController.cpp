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
    Position foundCharacter = seesCharacter();
    vector<Position> newPath = m_map->getPathTo(m_map->findCharacter(dynamic_cast<Character*> (this)), Position(5, 5));
    std::reverse(newPath.begin(), newPath.end());
    if (newPath.size() != 0)
        m_lastPath = newPath;

    if (m_lastPath.size() == 0)
        return 5;

    Position dp = m_map->findCharacter(dynamic_cast<Character*> (this)) - m_lastPath.at(0);

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

    return 0;




}

Position AttackController::seesCharacter() {
    return Position(0, 0);
}