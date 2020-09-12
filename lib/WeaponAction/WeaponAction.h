#ifndef WeaponAction_h
#define WeaponAction_h
#define TRIGGER 11
#define SHOOT_LIGHT 13
#define MODE_SWITCH 2
#define RELOAD_SWITCH 7
#define RELOAD_LIGHT 8
#include "Arduino.h"

class WeaponAction {
    
    private:
      int _damage;            
      int _chargerSize;       // Number of bullets allowed for each charger.
      int _chargerCounter;    // Number of available chargers.
      int _ammoCounter;   // Number of bullets in current charger.
      int _totalAmmo;     // _chargerCounter * _chargerSize
      int _shootInterval;     // Time between shoots.
      int _shootCounter;      // For statics
      bool _automaticMode;

     public:
        WeaponAction(int chargerSize, int numOfChargers, int damage, int shootInterval);  // Constructor
        void shoot();
        void substractAmmo();
        void reload();


      // GETTERS:

        int getAmmoInCharger();   
        int getTotalAmmo();
        int getShootCounter();   
};

#endif