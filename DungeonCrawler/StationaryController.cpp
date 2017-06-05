/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.cpp
 * Author: sebastian
 * 
 * Created on May 21, 2017, 1:51 PM
 */

#include "StationaryController.h"

StationaryController::StationaryController(Character* character) : Controller(character){
}
/*
StationaryController::StationaryController(const StationaryController& orig) {
}*/

StationaryController::~StationaryController() {
}

int StationaryController::move(){
    return 5;
}

std::string StationaryController::getControllerName(){
    return "StationaryController";
}