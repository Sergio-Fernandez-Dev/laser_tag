
/*#####################################################################
Esta clase establece la configuración inicial para cada tipo de arma.
#####################################################################*/

#ifndef ConfigWeapon_h
#define ConfigWeapon_h

#include <Arduino.h>

class ConfigWeapon {

    private:
        int _gun[];
        int _machineGun[];
        int _sniper[];
    public:
        ConfigWeapon();
        void gun(int  gun[]);
        void machineGun(struct weapon[]);
        void sniper(struct weapon[]);
};

#endif