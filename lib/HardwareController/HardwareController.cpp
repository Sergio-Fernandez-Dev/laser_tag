#include <HardwareController.h>
#include <WeaponAction.h>
#include <Arduino.h>

HardwareController::HardwareController()
{
    _timeCounter = 0;
    _ledStatus = true;
    _changeLedStatus = false;
    _loopCounter = 0;
    _stopChecking = false;
}

void HardwareController::checkShoot(bool shootConfirmationValue)
{
    if (shootConfirmationValue)
    {
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter < 2)
        {
            _stopChecking = false; // Value reset
            bool aux;
            digitalWrite(SHOOT_LIGHT, _ledStatus);
            _timeCounter = millis();
            aux = _ledStatus; // Changes the status of the boolean value
            _ledStatus = _changeLedStatus;
            _changeLedStatus = aux;
            _loopCounter += 1;          
        }
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter == 2)
        {
            _loopCounter = 0;
            _stopChecking = _ledStatus;
        }
    }
}

bool HardwareController::getStopChecking() { return _stopChecking; }