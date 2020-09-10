#ifndef Weapon_h
#define Weapon_h
#define TRIGGER 13
#define STATUSLIGHT 12
#define MODESWITCH 2
#include "Arduino.h"

class Weapon {
    
    private:
      int _damage;
      int _chargerSize;
      int _shootInterval;
      int _munitionCounter;
      int _shootCounter;
      bool _stillAlive;

     public:
        Weapon(int, int,int);
        void shoot();
        void substractMunition();
        void rechargeMunition();
        void substractHealth();

      // GETTERS:

        int getMunition();   
        int getShootCounter();   
};

#endif