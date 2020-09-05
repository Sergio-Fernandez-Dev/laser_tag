#ifndef Weapon_h
#define Weapon_h

#include "Arduino.h"

class Weapon
  {
    
    private:
      int _damage;
      int _munition; 
      struct _gun;
      struct _machinegun;
      struct _sniper;
      

     public:
      Weapon();
      void substractMunition();
      void rechargeMunition();
      void substractHealth();
      int getMunition();
      
  };

#endif