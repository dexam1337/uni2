/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.cpp
 * Author: sebastian
 * 
 * Created on 11. Mai 2017, 22:55
 */

#include "Active.h"
#include "Passive.h"
/*
Active::Active() : Tile(nullptr) {
    m_linked = nullptr;
    m_status = false;
}
*/
Active::Active(Passive* linked) : Tile(nullptr) {
    m_linked = linked;
    m_status = false;
}

/*
Active::Active(const Active& orig) : Tile(){
}*/

Active::~Active() {
    m_linked = nullptr;
}

void Active::use() {
    if (m_linked != nullptr)
        m_linked->use();
    if (m_status == true) {
        m_status = false; // code when active tile is disabled
    } else {
        m_status = true; //code when tile is activated
    }
}

void Active::setStatus(bool status) {
    if (m_linked != nullptr)
        m_linked->setStatus(status);
    m_status = status;
}

bool Active::getStatus() {
    return m_status;
}

void Active::setLinked(Passive* linked){
    m_linked = linked;
}