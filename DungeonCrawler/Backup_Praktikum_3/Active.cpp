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

#include <vector>

#include "Active.h"
#include "Passive.h"

/*
Active::Active() : Tile(nullptr) {
    m_linked = nullptr;
    m_status = false;
}
 */
Active::Active(Passive* linked) : Tile(nullptr) {
    m_linked.push_back(linked);
    m_status = false;
}

/*
Active::Active(const Active& orig) : Tile(){
}*/

Active::~Active() {
    m_linked.clear();
}

void Active::use() {
    for (int i = 0; i < m_linked.size(); i++) {
        if (m_linked.at(i) != nullptr)
            m_linked.at(i)->use();
        if (m_status == true) {
            m_status = false; // code when active tile is disabled
        } else {
            m_status = true; //code when tile is activated
        }
    }
}

void Active::setStatus(bool status) {
    for (int i = 0; i < m_linked.size(); i++) {
        if (m_linked.at(i) != nullptr)
            m_linked.at(i)->setStatus(status);
        m_status = status;
    }
}

bool Active::getStatus() {
    return m_status;
}

void Active::setLinked(Passive* linked) {
    m_linked.push_back(linked);
}