#include "DragonSword.h"

DragonSword::DragonSword()
{
    m_Name = "屠龙刀";
    m_Basedamage = 40;
    SuckRate = 30;
    CritRate = 35;
    HoldRate = 40;
}
bool DragonSword::istrigger(int rate)
{
    int rand_num = rand()%100+1;
    if(rate >= rand_num)
        return true;
    return false;
}
int DragonSword::getBaseDamage()
{
    return m_Basedamage;
}
int DragonSword::getSuckBlood()
{
    if(istrigger(SuckRate))
        return m_Basedamage/2;
    return 0;
}
bool DragonSword::getHold()
{
    if(istrigger(HoldRate))
        return true;
    return false;
}
bool DragonSword::getCrit()
{
    if(istrigger(CritRate))
        return true;
    return false;
}