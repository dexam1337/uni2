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

class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    virtual int modifyStrength(int strength) = 0;
    virtual int modifyStamina(int stamina) = 0;
private:

};

class ArmingSword : public Item{
public:
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Greatsword : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Club : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Rapier : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Dagger : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Gambeson : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class MailArmour : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Shield : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class FullPlateArmour : public Item{
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};


#endif /* ITEM_H */
