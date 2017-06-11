/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.h
 * Author: sebastian
 *
 * Created on 11. Juni 2017, 20:37
 */

#ifndef POSITION_H
#define POSITION_H

#include <iostream>
using namespace std;

struct Position {    
    Position();
    Position(int x, int y);
    //Position(const Position& orig);
    //virtual ~Position();
    
    int height;
    int width;

    friend bool operator==(const Position& lhs,const Position& rhs) {return (lhs.height == rhs.height && lhs.width == rhs.width);}; //funktioniert nicht ohne friend????
    bool operator!=(const Position& rhs) {return !((*this) == rhs);}; //hier schon?? warum?
    friend istream& operator>>(istream& inputstream, Position& pos);
    friend ostream& operator<<(ostream& outputstream, const Position& pos);
    bool operator<(const Position& rechts);
    inline bool operator> (const Position& rechts);
};



struct Kante{
    
    Position m_pos1, m_pos2;
    Kante(Position pos1, Position pos2);
    
    bool operator<(const Kante& rechts);
    bool operator>(const Kante& rechts);
    
};
#endif /* POSITION_H */

