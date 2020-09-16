#include <Arduino.h>
#include <WeaponAction.h>
#include <HardwareController.h>

WeaponAction weapon(10,10,10,500);
HardwareController controller;

int trigger;
int reloader;

void setup()
{
   Serial.begin(9600);
   pinMode(TRIGGER, INPUT);
   pinMode(SHOOT_LIGHT, OUTPUT);
   
   pinMode(RELOAD_SWITCH, INPUT);
   pinMode(RELOAD_LIGHT, OUTPUT); 
}
 
void loop()
{
   
   trigger = digitalRead(TRIGGER);
   if (trigger == HIGH)
   {
      weapon.shoot();
      Serial.print("Numero disparos: ");
      Serial.println(weapon.getShootCounter());
      Serial.print("Numero balas en cargador: ");
      Serial.println(weapon.getAmmoInCharger());
      Serial.print("Numero total de balas: ");
      Serial.println(weapon.getTotalAmmo());
   }

   controller.checkShoot(weapon.getShootConfirmation());
   controller.checkReloadStatus(weapon.getReloadStatus());
     
   reloader = digitalRead(RELOAD_SWITCH);
   if (reloader == HIGH)
   {
      weapon.reload();
      Serial.print("Numero disparos: ");
      Serial.println(weapon.getShootCounter());
      Serial.print("Numero balas en cargador: ");
      Serial.println(weapon.getAmmoInCharger());
      Serial.print("Numero total de balas: ");
      Serial.println(weapon.getTotalAmmo());
   }     
}