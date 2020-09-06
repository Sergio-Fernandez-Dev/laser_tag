#include <Arduino.h>
#include <Weapon.h>

Weapon::Weapon(int chargerSize, int damage, int shootInterval)
{
  _chargerSize = chargerSize;
  _damage = damage;
  _shootInterval = shootInterval; 
  _munitionCounter = chargerSize;    


};