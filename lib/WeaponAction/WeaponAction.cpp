#include <Arduino.h>
#include <WeaponAction.h>

WeaponAction::WeaponAction(int chargerSize, int numOfChargers, int damage, int shootInterval)
{
  _chargerSize = chargerSize;
  _damage = damage;                        
  _shootInterval = shootInterval;     
  _ammoCounter = chargerSize;      
  _chargerCounter = numOfChargers;     
  _totalAmmo = chargerSize * numOfChargers; 
  _shootCounter = 0;    
  _automaticMode = false;
}

void WeaponAction::shoot()
{
  Serial.println("Entrando en shoot()");
  if (_ammoCounter > 0)
  {
    int shootDuration = 300;
    unsigned long timeCounter;
    if (_automaticMode)
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
        substractAmmo();
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
        substractAmmo();
    } 
  } 
  else
  {
    substractAmmo();
  }
  
}

void WeaponAction::substractAmmo()
{
  Serial.println("Entrando en substractAmmo()");
  if (_ammoCounter > 0)
  {
    _ammoCounter -=1;
      if (_ammoCounter == 0)
      {
        digitalWrite(RELOAD_LIGHT, HIGH);
      }
  }
}

void WeaponAction::reload()
{
  Serial.println("Entrando en reload()");
  if (_totalAmmo > 0)
  { 
    while (_ammoCounter < _chargerSize && _totalAmmo > 0)
    {
      _ammoCounter += 1;
      _totalAmmo -= 1;
    }
    digitalWrite(RELOAD_LIGHT, LOW);
  }
}

  // GETTERS
int WeaponAction::getAmmoInCharger() {return _ammoCounter;}
int WeaponAction::getTotalAmmo() {return _totalAmmo;}
int WeaponAction::getShootCounter() {return _shootCounter;}