#include <Arduino.h>
#include <WeaponAction.h>
#include <HardwareController.h>

WeaponAction weapon(3,3,10,500);
HardwareController controller(true);

int pushed1;
int pushed2;

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
   
   pushed1 = digitalRead(TRIGGER);
   if (pushed1 == HIGH)
   {
      weapon.shoot();
      delay(100);
      Serial.print("Numero disparos: ");
      Serial.println(weapon.getShootCounter());
      delay(100);
      Serial.print("Numero balas en cargador: ");
      Serial.println(weapon.getAmmoInCharger());
      delay(100);
      Serial.print("Numero total de balas: ");
      Serial.println(weapon.getTotalAmmo());
      delay(100);
   }

   controller.checkShoot(weapon.getShootConfirmation());
     
   pushed2= digitalRead(RELOAD_SWITCH);
   if (pushed2 == HIGH)
   {
      weapon.reload();
      delay(100);
      Serial.print("Numero disparos: ");
      Serial.println(weapon.getShootCounter());
      delay(100);
      Serial.print("Numero balas en cargador: ");
      Serial.println(weapon.getAmmoInCharger());
      delay(100);
      Serial.print("Numero total de balas: ");
      Serial.println(weapon.getTotalAmmo());
      delay(100);
   }
      
}