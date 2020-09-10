#include <Arduino.h>
#include <Weapon.h>

Weapon::Weapon(int chargerSize, int damage, int shootInterval)
{
  _chargerSize = chargerSize;
  _damage = damage;
  _shootInterval = shootInterval; 
  _munitionCounter = chargerSize;    
  _shootCounter = 0;
  _stillAlive = true;
}

void Weapon::shoot(){
  if (_stillAlive == true && _munitionCounter > 0)
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
  if (_munitionCounter < 0)
  {
    _munitionCounter -=1;
  }
  else
  {
    digitalWrite(RELOAD_LIGHT, HIGH);
  }
}

void Weapon::reload()
{
  _munitionCounter = _chargerSize;
  digitalWrite(RELOAD_LIGHT, LOW);
}