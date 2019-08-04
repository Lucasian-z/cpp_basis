#include "Knife.h"
Knife::Knife()
{
    m_Name = "小刀";
    m_Basedamage = 20;
}
int Knife::getBaseDamage()
{
    return m_Basedamage;
}
int Knife::getSuckBlood()
{
    return 0;
}
bool Knife::getHold()
{
    return false;
}
bool Knife::getCrit()
{
    return false;
}