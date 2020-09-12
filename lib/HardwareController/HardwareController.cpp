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
            _stopChecking = false;
            bool aux;
            digitalWrite(SHOOT_LIGHT, _ledStatus);
            Serial.print("Dentro del primer if, _ledStatus: ");
            Serial.println(_ledStatus);
            _timeCounter = millis();
            aux = _ledStatus; // Changes the status of the boolean value
            _ledStatus = _changeLedStatus;
            _changeLedStatus = aux;
            Serial.println(_ledStatus);
            _loopCounter += 1;
            Serial.print("counter: ");
            Serial.println(_loopCounter);
            Serial.print("Confirmación clase Weapon: ");
            Serial.println(shootConfirmationValue);
            Serial.print("Confirmación clase Hardware: ");
            Serial.println(_stopChecking);
        }
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter == 2)
        {
            _loopCounter = 0;
            _stopChecking = _ledStatus;
            Serial.print("Entrando al ultimo if, counter: ");
            Serial.println(_loopCounter);
            Serial.print("Confirmación clase Weapon: ");
            Serial.println(shootConfirmationValue);
            Serial.print("Confirmación clase Hardware: ");
            Serial.println(_stopChecking);
        }
    }
}

bool HardwareController::getStopChecking() { return _stopChecking; }