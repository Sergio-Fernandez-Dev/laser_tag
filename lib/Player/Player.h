#ifndef Player_h
#define Player_h

#include "Arduino.h"

class Player 
  {
    
    private:
      int _damage;
      int _health;
      int _fullCharger; 
      int _munitionCounter;
      int _life;

     public:
      Player(int life, int health, int munition, int damage);
      void substractMunition();
      void rechargeMunition();
      void substractHealth();
      void substractLife();
      int getLife();
      int getMunition();
      int getHealth();
  };

#endif