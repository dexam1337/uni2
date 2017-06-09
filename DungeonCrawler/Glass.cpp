/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Glass.cpp
 * Author: sebastian
 * 
 * Created on 9. Juni 2017, 19:49
 */

#include "Glass.h"

Glass::Glass() : Wall(){
}

Glass::Glass(const Glass& orig) {
}

Glass::~Glass() {
}

char Glass::print(){
    return ' ';
}

char Glass::save(){
    return this->print();
}

bool Glass::isTransparent(){
    return true;
}