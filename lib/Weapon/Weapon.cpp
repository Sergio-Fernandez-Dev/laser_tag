#include <Arduino.h>
#include <Weapon.h>

Weapon::Weapon(int chargerSize, int damage, int shootInterval)
{
  _chargerSize = chargerSize;
  _damage = damage;
  _shootInterval = shootInterval; 
  _munitionCounter = chargerSize;    
  stillAlive = true;
}

void Weapon::shoot(int modePin, int shootInterval){
  unsigned long timeCounter;
  int shootDuration = 300;
  if (digitalRead(MODESWITCH) == LOW){
    do
    {
      digitalWrite(STATUSLIGHT, HIGH);
      if (millis() >= timeCounter + shootDuration){
        timeCounter = millis();
        digitalWrite(STATUSLIGHT, LOW);

      }
    } while (digitalRead(TRIGGER) == LOW && timeCounter >  timeCounter + shootInterval);
  }
}