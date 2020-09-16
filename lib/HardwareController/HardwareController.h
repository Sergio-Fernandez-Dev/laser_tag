#ifndef HardwareController_h
#define HardwareController_h

#define TRIGGER 11
#define SHOOT_LIGHT 13
#define MODE_SWITCH 2
#define RELOAD_SWITCH 7
#define RELOAD_LIGHT 8
#define FIRE_DURATION 300

#include <Arduino.h>

class HardwareController
{
private:
    unsigned long _timeCounter;
    bool _ledStatus;
    bool _changeLedStatus;
    int _loopCounter;
    bool _stopChecking;
public:
    HardwareController();
    void checkShoot(bool *ptrShootConfirmation); // Checks if WeaponAction::shoot() was activated & puts on the fire light 
    bool getStopChecking();
};

#endif