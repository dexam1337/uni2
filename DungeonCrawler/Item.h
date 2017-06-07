/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: sebastian
 *
 * Created on May 19, 2017, 1:07 PM
 */

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
//#include <string>
class Item {
public:
    Item(std::string name);
    Item(const Item& orig);
    virtual ~Item();
    virtual int modifyStrength(int strength) = 0;
    virtual int modifyStamina(int stamina) = 0;
    char print();
    friend std::ostream& operator<<(std::ostream& outputstream, Item& item);
private:
    char m_symbol;
    std::string m_name;
};

class ArmingSword : public Item{
public:
    ArmingSword();
    //1ArmingSword(const ArmingSword& orig);
   // ~ArmingSword();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Greatsword : public Item{
    public:
    Greatsword();
    //Greatsword(const Greatsword& orig);
    //~Greatsword();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Club : public Item{
    public:
    Club();
    //Club(const Club& orig);
    //~Club();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Rapier : public Item{
    public:
    Rapier();
    //Rapier(const Rapier& orig);
    //~Rapier();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Dagger : public Item{
    public:
    Dagger();
    //Dagger(const Dagger& orig);
    //~Dagger();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Gambeson : public Item{
    public:
    Gambeson();
    //Gambeson(const Gambeson& orig);
    //~Gambeson();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class MailArmour : public Item{
    public:
    MailArmour();
    //MailArmour(const MailArmour& orig);
    //~MailArmour();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Shield : public Item{
    public:
    Shield();
    //Shield(const Shield& orig);
    //~Shield();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class FullPlateArmour : public Item{
    public:
    FullPlateArmour();
    //FullPlateArmour(const FullPlateArmour& orig);
    //~FullPlateArmour();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};


#endif /* ITEM_H */
