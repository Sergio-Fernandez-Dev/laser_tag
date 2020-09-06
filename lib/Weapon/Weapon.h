#ifndef Weapon_h
#define Weapon_h

#include "Arduino.h"

class Weapon
  {
    
    private:
      int _damage;
      int _chargerSize;
      int _munitionCounter;
      float _shootInterval;
      

     public:
      Weapon(int chargerSize, int damage, int shootInterval);
      void substractMunition();
      void rechargeMunition();
      void substractHealth();
      int getMunition();
      
  };

#endif