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

#include <memory>

#include "AttackController.h"
#include "DungeonMap.h"

AttackController::AttackController(Character* character, DungeonMap* map) : Controller(character){
    m_map = map;
}

//AttackController::AttackController(const AttackController& orig) {
//}

AttackController::~AttackController() {
}

std::string AttackController::getControllerName(){
    return "AttackController";
}

int AttackController::move(){
    Character* foundCharacter = seesCharacter();
    vector<Position> newPath = m_map->getPathTo(m_map->findCharacter(dynamic_cast<Character*>(this)), m_map->findCharacter(foundCharacter));
    if(newPath.size()!=0)
        m_lastPath = newPath;
    
    
    
    if(m_lastPath.size() == 0)
        return 5;
    
}

Character* AttackController::seesCharacter(){
    return nullptr;
}