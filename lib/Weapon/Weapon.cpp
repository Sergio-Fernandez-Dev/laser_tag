#include <Arduino.h>
#include <Weapon.h>

Weapon::Weapon(int chargerSize, int damage, int shootInterval[2])
{
  _chargerSize = chargerSize;
  _damage = damage;
  _shootInterval[2]= shootInterval[2]; 
  _munitionCounter = chargerSize;    
  stillAlive = true;
};