#include <Arduino.h>
#include <Player.h>
#include <Weapon.h>
#include <ConfigWeapon.h>

ConfigWeapon configweapon;

void setup()
{
   Serial.begin(9600);
}
 
void loop()
{
   Serial.println(configweapon._gun[0]);
   
}