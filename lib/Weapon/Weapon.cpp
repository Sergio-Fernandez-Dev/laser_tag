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
  if (_stillAlive == true)
  {
    int shootDuration = 300;
    unsigned long timeCounter;
    if (digitalRead(MODESWITCH) == LOW)
    {
      do
      {
        digitalWrite(STATUSLIGHT, HIGH);
        if (millis() >= timeCounter + shootDuration)
        {
          digitalWrite(STATUSLIGHT, LOW);
          timeCounter = millis();
        }
        _shootCounter += 1;
        substractMunition();
      } while (digitalRead(TRIGGER) == LOW && timeCounter >  timeCounter + _shootInterval);
    }
    else
    {
        digitalWrite(STATUSLIGHT, HIGH);
        if (millis() >= timeCounter + shootDuration)
        {
          digitalWrite(STATUSLIGHT, LOW);
          timeCounter = millis();
        }
        _shootCounter += 1;
        substractMunition();
    } 
  }
}