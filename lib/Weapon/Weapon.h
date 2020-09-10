#ifndef Weapon_h
#define Weapon_h
#define TRIGGER 13
#define SHOOT_LIGHT 12
#define MODE_SWITCH 2
#define RELOAD_SWITCH 7
#define RELOAD_LIGHT 8
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
        void reload();
        void substractHealth();

      // GETTERS:

        int getMunition();   
        int getShootCounter();   
};

#endif