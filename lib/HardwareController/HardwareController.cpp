#include <HardwareController.h>
#include <WeaponAction.h>

unsigned long _timeCounter = 0;
bool _ledStatus = true;
bool _changeLedStatus = false;
bool aux;
int _loopCounter = 1;

void HardwareController::checkShoot(bool *shootConfirmation)
{
    if (shootConfirmation)
    {
        if (millis() - _timeCounter >= FIRE_DURATION)           
        {
            digitalWrite(SHOOT_LIGHT, _ledStatus);
            _timeCounter = millis();
            aux = _ledStatus;                                   // Changes the status of the boolean value
            _ledStatus = _changeLedStatus;
            _changeLedStatus = aux;
            Serial.begin(_ledStatus);
            if (_loopCounter == 2)                              // When the SHOOT_LIGHT is off, changes the shootConfirmation status
            {
                bool *shootConfirmation = false;
            }
            else
            {
                _loopCounter += 1;
            }            
        }
    }
}