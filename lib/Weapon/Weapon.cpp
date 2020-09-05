#include <Arduino.h>
#include <Weapon.h>

Weapon::Weapon()
{
    struct _gun{
      int _munition = 10;
      int _damage = 10;
    };

    struct _machinegun{
      int _munition = 20;
      int _damage = 25;
    };

    struct _sniper{
      int _munition = 5;
      int _damage = 50;
    };

}