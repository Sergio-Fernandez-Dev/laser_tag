#ifndef GameConfig_h
#define GameConfig_h
#include <Arduino.h>
#include <Player.h>
#include <Weapon.h>

class GameConfig
{
public:

    GameConfig(Player playerConfig, Weapon weaponConfig);

private:

    Player _playerConfig;
    Weapon _weaponConfig;
};

#endif