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

Item::Item(std::string name) {
    m_symbol = '*';
    m_name = name;
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

char Item::print(){
    return m_symbol;
}

std::ostream& operator<<(std::ostream& outputstream, Item& item){
    outputstream << "Item " << item.m_name << " "; //Kein endl wegen position
    return outputstream;
}

ArmingSword::ArmingSword() : Item("ArmingSword"){
}

int ArmingSword::modifyStrength(int strength)  {
    return 3;
}

int ArmingSword::modifyStamina(int stamina)  {
    return 0;
}

Greatsword::Greatsword() : Item("Greatsword"){
}
int Greatsword::modifyStrength(int strength)  {
    return 5;
}

int Greatsword::modifyStamina(int stamina)  {
    return -1;
}

Club::Club() : Item("Club"){
}
int Club::modifyStrength(int strength)  {
    return (strength / 2);
}

int Club::modifyStamina(int stamina)  {
    return 0;
}

Rapier::Rapier() : Item("Rapier"){
}
int Rapier::modifyStrength(int strength)  {
    return 2;
}

int Rapier::modifyStamina(int stamina)  {
    return 1;
}

Dagger::Dagger() : Item("Dagger"){
}
int Dagger::modifyStrength(int strength)  {
    return 2;
}

int Dagger::modifyStamina(int stamina)  {
    return 1;
}

Gambeson::Gambeson() : Item("Gambeson"){
}
int Gambeson::modifyStrength(int strength)  {
    return 0;
}

int Gambeson::modifyStamina(int stamina)  {
    return 1;
}

MailArmour::MailArmour() : Item("MailArmour"){
}
int MailArmour::modifyStrength(int strength)  {
    return 3;
}

int MailArmour::modifyStamina(int stamina)  {
    return 3;
}

Shield::Shield() : Item("Shield"){
}
int Shield::modifyStrength(int strength)  {
    return -1;
}

int Shield::modifyStamina(int stamina)  {
    return stamina;
}

FullPlateArmour::FullPlateArmour() : Item("FullPlateArmour"){
}
int FullPlateArmour::modifyStrength(int strength)  {
    return -2;
}

int FullPlateArmour::modifyStamina(int stamina)  {
    return 6;
}