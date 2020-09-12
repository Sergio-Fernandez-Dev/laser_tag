#include <HardwareController.h>
#include <WeaponAction.h>
#include <Arduino.h>

HardwareController::HardwareController(bool ledStatus)
{
    _timeCounter = 0;
    _ledStatus = ledStatus;
    _changeLedStatus = false;
    aux;
    _loopCounter = 0;
}

void HardwareController::checkShoot(bool shootConfirmationValue)
{
    if (shootConfirmationValue)
    {
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter < 2)           
        {
            digitalWrite(SHOOT_LIGHT, _ledStatus);
            Serial.print("Dentro del primer if, _ledStatus: ");
            Serial.println(_ledStatus);
            _timeCounter = millis();
            aux = _ledStatus;                                   // Changes the status of the boolean value
            _ledStatus = _changeLedStatus;
            _changeLedStatus = aux;
            Serial.println(_ledStatus);
            _loopCounter += 1;        
            Serial.print("counter: ");
            Serial.println(_loopCounter);    
        }
        if (millis() - _timeCounter >= FIRE_DURATION && _loopCounter == 2)  
        {
            _loopCounter = 0;   
            Serial.print("Entrando al ultimo if, counter: ");
            Serial.println(_loopCounter);  
        }
    }
}