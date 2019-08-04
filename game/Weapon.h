#pragma once
#include <iostream>
#include <string>
using namespace std;

class Weapon
{
public:
    virtual int getSuckBlood() = 0;//吸血
    virtual bool getCrit() = 0;//暴击
    virtual bool getHold() = 0;//定身
    virtual int getBaseDamage() = 0;//获取基础伤害
    string m_Name;//武器名称
    int m_Basedamage;//基础伤害
};