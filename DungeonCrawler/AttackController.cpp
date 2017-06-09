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

AttackController::AttackController(Character* character) : Controller(character){
}

//AttackController::AttackController(const AttackController& orig) {
//}

AttackController::~AttackController() {
}

std::string AttackController::getControllerName(){
    return "AttackController";
}

int AttackController::move(){
    
}