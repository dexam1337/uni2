/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.cpp
 * Author: sebastian
 * 
 * Created on 11. Juni 2017, 20:37
 */

#include "Position.h"

Position::Position() {
    height = 0;
    width = 0;
}

Position::Position(int x, int y) {
    height = x;
    width = y;
}

//Position::Position(const Position& orig) {
//}

//Position::~Position() {
//}

istream& operator>>(istream& inputstream, Position& pos) {
    char tmp;
    inputstream >> pos.height >> tmp >> pos.width;
    return inputstream;
}

ostream& operator<<(ostream& outputstream, const Position& pos) {
    outputstream << pos.height << "/" << pos.width;
    return outputstream;
}

bool Position::operator<(const Position& rechts) {
    if (this->height < rechts.height)
        return true;
    if (this->width < rechts.width && this->height == rechts.height)
        return true;
    else
        return false;
}

inline bool Position::operator>(const Position& rechts) {
    return (*this < rechts);
}

Position Position::operator-(const Position& rechts){
    return Position((this->height-rechts.height), (this->width-rechts.width));
}

Position Position::operator+(const Position& rechts){
    return Position((this->height+rechts.height), (this->width+rechts.width));
}

Kante::Kante(Position pos1, Position pos2) {
    if (pos1 > pos2) {
        m_pos1 = pos2;
        m_pos2 = pos1;
    } else {
        m_pos1 = pos1;
        m_pos2 = pos2;
    }

}

/*bool Kante::operator<(const Kante& rechts) {
    if((*this).m_pos1 < rechts.m_pos1)
        return true;
    else
        return false;

}
*/
bool operator<(const Kante& links,const Kante& rechts) {
    if(links.m_pos1.height < rechts.m_pos1.height)
        return true;
    if(links.m_pos1.height == rechts.m_pos1.height && links.m_pos2.width < rechts.m_pos2.width)
        return true;
    else
        return false;

}

inline bool Kante::operator>(const Kante& rechts) {
    return (*this < rechts);
}