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
    Controller::setCharacter(character);
}

//AttackController::AttackController(const AttackController& orig) {
//}

AttackController::~AttackController() {
}

std::string AttackController::getControllerName() {
    return "AttackController";
}

int AttackController::move() {
    seesCharacter();

    if (m_lastPath.size() == 0)
        return 5;

    Position lp = m_map->findCharacter(Controller::getCharacter());
    Position dp = lp - m_lastPath.at(0);
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
    else {
        cerr << "alter Pfad ungueltig geworden.";
        m_lastPath.clear();
        return 5;
    }



}

void AttackController::seesCharacter() {
    vector<int> dim = m_map->getDimensions();
    vector<Position> shortest, current;
    Position pos(0, 0);
    for (pos.height; pos.height < dim.at(0); pos.height++) {
        for (pos.width; pos.width < dim.at(1); pos.width++) {
            if (m_map->findTile(pos)->getCharacter() != nullptr && m_map->findTile(pos)->getCharacter() != Controller::getCharacter()) {
                if (m_map->hasLineOfSight(m_map->findCharacter(Controller::getCharacter()), pos)) {
                    current = m_map->getPathTo(m_map->findCharacter(Controller::getCharacter()), pos);
                    if (shortest.size() == 0 || (shortest.size() > current.size() && current.size() != 0)) {
                        shortest = current;
                    }
                }

            }


        }
        pos.width = 0;
    }


    if (shortest.size() != 0)
        m_lastPath = shortest;
}