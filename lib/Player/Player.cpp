#include "Arduino.h"
#include "Player.h"

Player::Player(int life, int health, int munition, int damage)
{
  _life = life;
  _health = health;
  _fullCharger = munition;
  _munitionCounter = munition;
  _damage = damage;
}

void Player::substractMunition()
{
  if (_munitionCounter < 0)
  {
    _munitionCounter -=1;
  }
  else
  {
    rechargeMunition();
  }
}
void Player::rechargeMunition()
{
  _munitionCounter = _fullCharger;
}
void Player::substractHealth()
{
  if (_health > 0)
  {
    _health -= _damage;
  }
  else 
  {
    substractLife();
  }
}
void Player::substractLife()
{
  if (_life > 0)
  {
    _life -= 1;
  }
  else
  {
    Serial.println("GAME OVER");
  }
}
int Player::getLife()
 {
    return _life;
 }
 int Player::getMunition()
 {
    return _munitionCounter;
 }
 int Player::getHealth()
 {
    return _health;
 }
