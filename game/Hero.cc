#include "Hero.h"
#include "Monster.h"

Hero::Hero()
{
    m_Name = "小胡";
    m_Atk = 30;//攻击力
    m_Def = 40;//防御力
    m_Hp = 1000;//血量
    weapon = nullptr;
}

void Hero::EquipmenWeapon(Weapon *wea)
{
    weapon = wea;//装备武器
    cout << "英雄:" << m_Name << "装备了武器:" << weapon->m_Name << endl;
}

void Hero::Attck(Monster *monster)
{
    int damage = 0;
    int addHp = 0;
    bool isHold = false;
    bool isCrit = false;
    if(weapon == nullptr)
    {
        damage = m_Atk;
        cout << "test" << endl;
    }
    else
    {
        damage = m_Atk + weapon->getBaseDamage();
        addHp = weapon->getSuckBlood();
        isHold = weapon->getHold();
        isCrit = weapon->getCrit();
    }
    if(isHold)
    {
        cout << "武器:" << weapon->m_Name << "触发定身效果，怪物停止攻击一回合" << endl;
    }
    if(isCrit)
    {
        damage *= 2;
        cout << "武器:" << weapon->m_Name << "触发暴击效果，造成双倍伤害" << endl;
    }
    if(addHp)
    {
        cout << "武器:"<< weapon->m_Name << "触发吸血效果，增加血量为:" << addHp << endl;
    }
    monster->isHold = isHold;
    int trueDamage = (damage-monster->m_Def)>0 ? (damage-monster->m_Def):1;
    monster->m_Hp -= trueDamage;
    m_Hp += addHp;
    cout << "英雄:" << m_Name <<"攻击怪物:" << monster->m_Name << "造成伤害:" << trueDamage<< endl;
}