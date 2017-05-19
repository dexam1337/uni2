/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: sebastian
 * 
 * Created on May 19, 2017, 1:07 PM
 */

#include "Item.h"

Item::Item() {
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

int ArmingSword::modifyStrength(int strength)  {
    return 3;
}

int ArmingSword::modifyStamina(int stamina)  {
    return 0;
}

int Greatsword::modifyStrength(int strength)  {
    return 5;
}

int Greatsword::modifyStamina(int stamina)  {
    return -1;
}

int Club::modifyStrength(int strength)  {
    return (strength / 2);
}

int Club::modifyStamina(int stamina)  {
    return 0;
}

int Rapier::modifyStrength(int strength)  {
    return 2;
}

int Rapier::modifyStamina(int stamina)  {
    return 1;
}

int Dagger::modifyStrength(int strength)  {
    return 2;
}

int Dagger::modifyStamina(int stamina)  {
    return 1;
}

int Gambeson::modifyStrength(int strength)  {
    return 0;
}

int Gambeson::modifyStamina(int stamina)  {
    return 1;
}

int MailArmour::modifyStrength(int strength)  {
    return 3;
}

int MailArmour::modifyStamina(int stamina)  {
    return 3;
}

int Shield::modifyStrength(int strength)  {
    return -1;
}

int Shield::modifyStamina(int stamina)  {
    return stamina;
}

int FullPlateArmour::modifyStrength(int strength)  {
    return -2;
}

int FullPlateArmour::modifyStamina(int stamina)  {
    return 6;
}