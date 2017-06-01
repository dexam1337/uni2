/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: sebastian
 * 
 * Created on 12. Mai 2017, 00:03
 */

#include "Controller.h"
#include "Character.h"

Controller::Controller(Character* character) {//warum soll controller seinen character kennen?
    m_character = character;
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
    m_character = nullptr;
}

Character* Controller::getCharacter(){
    return m_character;
}

