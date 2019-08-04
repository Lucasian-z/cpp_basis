#pragma once
#include "Weapon.h"
#include "DragonSword.h"
#include "Knife.h"
class Monster;//声明怪物类
class Hero
{
public:
    Hero();
    string m_Name;//英雄名称
    int m_Hp;//英雄血量
    int m_Def;//英雄防御
    int m_Atk;//攻击力
    Weapon *weapon;
    void EquipmenWeapon(Weapon *);
    void Attck(Monster *monster);
};