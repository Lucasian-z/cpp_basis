#include "Weapon.h"
#include "Knife.h"
#include "DragonSword.h"
#include "Hero.h"
#include "Monster.h"
#include <iostream>
void play()
{
    //构造对象
    Hero *hero = new Hero;
    Monster *monster = new Monster;
    Knife *knife = new Knife;
    DragonSword *dragonsword = new DragonSword;
    cout << "请选择武器：" << endl
         << "1.赤手空拳" << endl
         << "2.小刀" << endl
         << "3.屠龙刀" << endl;
    int oper = 0;
    cin >> oper;
    switch (oper)
    {
    case 1:
        cout << "你太强了" << endl;
        break;
    case 2:
        hero->EquipmenWeapon(knife);
        break;
    case 3:
        hero->EquipmenWeapon(dragonsword);
        break;
    default:
        break;
    }
    getchar();
    int round = 1;
    while(true)
    {
        getchar();
        system("clear");
        cout << "--------第"<< round << "回合开始--------" << endl;
        
        if(hero->m_Hp <= 0)
        {
            cout << "英雄:" << hero->m_Name << "不幸身亡" << endl;
            break;
        }
        hero->Attck(monster);
        
        if(monster->m_Hp <= 0)
        {
            
            cout << "怪物:" << monster->m_Name << "已挂，顺利通关" << endl;
            break;
        }
        
        monster->Attack(hero);
        cout <<"hh"<< endl;
        if(hero->m_Hp <= 0)
        {
            cout << "英雄:" << hero->m_Name << "不幸身亡" << endl;
            break;
        }
        cout << "英雄:" << hero->m_Name << "剩余血量为:" << hero->m_Hp << endl;
        cout << "怪物:" << monster->m_Name << "剩余血量为:" << monster->m_Hp << endl;
        ++round;
    }
}

int main(int argc, char *argv[])
{
    srand((unsigned int)time(nullptr));
    play();
    return 0;
}