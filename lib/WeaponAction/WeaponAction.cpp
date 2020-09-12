#include <Arduino.h>
#include <WeaponAction.h>
#include <HardwareController.h>

WeaponAction::WeaponAction(int chargerSize, int numOfChargers, int damage,  int shootInterval)
{
  _chargerSize = chargerSize;
  _damage = damage;                        
  _shootInterval = shootInterval;     
  _ammoCounter = chargerSize;      
  _chargerCounter = numOfChargers;     
  _totalAmmo = chargerSize * numOfChargers; 
  _shootCounter = 0;    
  _shootConfirmation = false;
  _automaticMode = false;
}

void WeaponAction::shoot()
{
  Serial.println("Entrando en shoot()");
  if (_ammoCounter > 0)
  {
        _shootCounter += 1;
        _shootConfirmation = true;

        substractAmmo();
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
bool WeaponAction::getShootConfirmation() {return _shootConfirmation;}

// SETTERS:
void WeaponAction::setShootConfirmation(){
  _shootConfirmation = false;
}
