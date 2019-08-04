#pragma once
#include "Weapon.h"
class DragonSword:public Weapon
{
public:
    DragonSword();
    virtual int getBaseDamage();
    virtual int getSuckBlood();
    virtual bool getHold();
    virtual bool getCrit();
    int SuckRate;//吸血率
    int HoldRate;//定身率
    int CritRate;//暴击率
    bool istrigger(int rate);
};