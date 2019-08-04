#include "Monster.h"

Monster::Monster()
{
    m_Name = "弗利沙";
    m_Atk = 300;
    m_Def = 40;
    m_Hp = 500;
    isHold = false;
}

void Monster::Attack(Hero *hero)
{
    int damage = m_Atk;
    if(isHold)
    {
        cout << "弗利沙被定身，此回合无法攻击" << endl;
        return;
    }
    damage = (damage - hero->m_Def)>0 ? (damage - hero->m_Def):1;
    hero->m_Hp -= damage;
    cout << "怪物:" << m_Name << "攻击了英雄:"<< hero->m_Name << " 造成了伤害:" << damage << endl;
}