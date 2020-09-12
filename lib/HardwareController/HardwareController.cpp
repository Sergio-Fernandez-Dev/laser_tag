#include <HardwareController.h>
#include <WeaponAction.h>

    unsigned long _timeCounter = 0;
    bool _ledStatus = true;  
    bool _changeLedStatus = false;
    bool aux;
    int loopCounter = 2;

void HardwareController::checkShoot(bool shootConfirmation )
{
    if (shootConfirmation){
        if (millis() - _timeCounter >= FIRE_DURATION)
        {
            digitalWrite(SHOOT_LIGHT, _ledStatus);
            _timeCounter = millis();
            aux = _ledStatus;
            _ledStatus = _changeLedStatus;
            _changeLedStatus = aux; 
            Serial.begin(_ledStatus);
            if (loopCounter == 2){
                bool value = false;
                WeaponAction::setShootConfirmation(value);
            }
        }
    }
}