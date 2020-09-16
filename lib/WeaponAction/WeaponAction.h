#ifndef WeaponAction_h
#define WeaponAction_h

#include "Arduino.h"

class WeaponAction
{    
    private:
      int _damage;            
      int _chargerSize;                       // Number of bullets allowed for each charger.
      int _chargerCounter;                    // Number of available chargers.
      int _ammoCounter;                       // Number of bullets in current charger.
      int _totalAmmo;                         // _chargerCounter * _chargerSize
      unsigned long _shootInterval;           // Time between shoots.
      int _shootCounter;                      // For statics
      bool _shootConfirmation;     
      bool _automaticMode;
      unsigned long _timeCounter;
      bool _reloadStatus;

    public:
      WeaponAction(int chargerSize, int numOfChargers, int damage, unsigned long shootInterval);  // Constructor
      void shoot();
      void substractAmmo();
      void reload();

      // GETTERS:
      int getAmmoInCharger();   
      int getTotalAmmo();
      int getShootCounter();  
      bool* getShootConfirmation();
      bool* getReloadStatus();

      //SETTERS:
      void setShootConfirmation();
    
};

#endif