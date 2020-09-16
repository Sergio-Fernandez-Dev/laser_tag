#include <HardwareController.h>
#include <WeaponAction.h>
#include <Arduino.h>

HardwareController::HardwareController()
{
    _timeCounter = 0;
    _ledStatus = true;
    _changeLedStatus = false;
    _loopCounter = 0;
}

void HardwareController::checkShoot(bool *ptrShootConfirmation) 
{
    if (*ptrShootConfirmation)
    {
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter < 2)
        {
            Serial.print("puntero Shoot confirmation primer if: ");
            Serial.println(*ptrShootConfirmation);
            bool aux;
            digitalWrite(SHOOT_LIGHT, _ledStatus);
            _timeCounter = millis();
            aux = _ledStatus; // Changes the status of the boolean value
            _ledStatus = _changeLedStatus;
            _changeLedStatus = aux;
            _loopCounter += 1;     
            Serial.print("Led Status primer if: ");
            Serial.println(_ledStatus);     
            Serial.print("loop: ");
            Serial.println(_loopCounter);   
        }
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter == 2)
        {
            _loopCounter = 0;
            *ptrShootConfirmation = false;
            Serial.print("puntero Shoot confirmation segundo if: ");
            Serial.println(*ptrShootConfirmation);
            Serial.print("Led Status segundo if: ");
            Serial.println(_ledStatus);    
        }
    }
}

// GETTERS
bool HardwareController::getStopChecking() { return _stopChecking; }