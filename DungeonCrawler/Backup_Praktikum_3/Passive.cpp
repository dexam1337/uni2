/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.cpp
 * Author: sebastian
 * 
 * Created on 11. Mai 2017, 22:55
 */

#include "Passive.h"

Passive::Passive() : Tile(nullptr){
    m_status = false;
}
/*
Passive::Passive(const Passive& orig) {
}*/

Passive::~Passive() { 
}

void Passive::use() {
    if (m_status == true) {
        m_status = false; // code when passive tile is disabled
    } else {
        m_status = true; //code when tile is activated
    }
}

void Passive::setStatus(bool status) {
    m_status = status;
}

bool Passive::getStatus() {
    return m_status;
}