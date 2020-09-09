#ifndef Weapon_h
#define Weapon_h
#define TRIGGER 13
#define STATUSLIGHT 12
#include "Arduino.h"

class Weapon {
    
    private:
      int _damage;
      int _chargerSize;
      int _shootInterval[2];
      int _munitionCounter;

     public:
        bool stillAlive;
        Weapon(int, int,int[2]);
        void substractMunition();
        void rechargeMunition();
        void substractHealth();
        int getMunition();      
};

#endif