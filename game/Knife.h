#pragma once
#include "Weapon.h"

class Knife:public Weapon
{
public:
    virtual int getBaseDamage();
    virtual int getSuckBlood();
    virtual bool getHold();
    virtual bool getCrit();
    Knife();
};