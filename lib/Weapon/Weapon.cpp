#include <Arduino.h>
#include <Weapon.h>

Weapon::Weapon(int chargerSize, int numOfChargers, int damage, int shootInterval)
{
  _chargerSize = chargerSize;
  _damage = damage;                        
  _shootInterval = shootInterval;     
  _ammoCounter = chargerSize;      
  _chargerCounter = numOfChargers;     
  _totalAmmo = chargerSize * numOfChargers; 
  _shootCounter = 0;    
}

void Weapon::shoot()
{
  if (_ammoCounter > 0)
  {
    int shootDuration = 300;
    unsigned long timeCounter;
    if (digitalRead(MODE_SWITCH) == LOW)
    {
      do
      {
        digitalWrite(SHOOT_LIGHT, HIGH);
        if (millis() >= timeCounter + shootDuration)
        {
          digitalWrite(SHOOT_LIGHT, LOW);
          timeCounter = millis();
        }
        _shootCounter += 1;
        substractMunition();
      } while (digitalRead(TRIGGER) == LOW && timeCounter >  timeCounter + _shootInterval);
    }
    else
    {
        digitalWrite(SHOOT_LIGHT, HIGH);
        if (millis() >= timeCounter + shootDuration)
        {
          digitalWrite(SHOOT_LIGHT, LOW);
          timeCounter = millis();
        }
        _shootCounter += 1;
        substractMunition();
    } 
  }
}

void Weapon::substractMunition()
{
  if (_ammoCounter > 0)
  {
    _ammoCounter -=1;
  }
  else
  {
    digitalWrite(RELOAD_LIGHT, HIGH);
  }
}

void Weapon::reload()
{
  if (_totalAmmo > 0)
  { 
    do
    {
      _ammoCounter += 1;
      _totalAmmo -= 1;
    } while (_ammoCounter < _chargerSize && _totalAmmo > 0);
    digitalWrite(RELOAD_LIGHT, LOW);
  }

}