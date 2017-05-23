/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.h
 * Author: sebastian
 *
 * Created on May 21, 2017, 1:51 PM
 */

#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

#include "Controller.h"


class StationaryController : public Controller{
public:
    StationaryController(Character* character);
    //StationaryController(const StationaryController& orig);
    virtual ~StationaryController();
    int move() override;
private:

};

#endif /* STATIONARYCONTROLLER_H */

