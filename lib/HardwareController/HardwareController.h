#ifndef HardwareController_h
#define HardwareController_h

#define TRIGGER 11
#define SHOOT_LIGHT 13
#define MODE_SWITCH 2
#define RELOAD_SWITCH 7
#define RELOAD_LIGHT 8

#include <Arduino.h>

class HardwareController
{
private:
    unsigned long _timer;
    unsigned long _fireDuration;
public:
    HardwareController(unsigned long timer, unsigned long fireDuration);
    void checkShoot(bool shootConfirmation); // Checks if WeaponAction::shoot() was activated & puts on the fire light 

};




#endif