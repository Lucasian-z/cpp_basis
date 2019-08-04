#pragma once
#include "Weapon.h"
#include "DragonSword.h"
#include "Knife.h"
#include "Hero.h"
class Monster
{
public:
    Monster();
    string m_Name;
    int m_Hp;//怪物血量
    int m_Def;//防御力
    int m_Atk;//攻击力
    bool isHold;
    void Attack(Hero *hero);
};