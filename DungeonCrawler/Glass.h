/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Glass.h
 * Author: sebastian
 *
 * Created on 9. Juni 2017, 19:49
 */

#ifndef GLASS_H
#define GLASS_H
#include "Wall.h"

class Glass : public Wall{
public:
    Glass();
    Glass(const Glass& orig);
    virtual ~Glass();
    
    char print() override;
    char save() override;
    bool isTransparent() override;
private:

};

#endif /* GLASS_H */

