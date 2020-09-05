#include <Arduino.h>
#include <IRremote.h>
#include <Player.h>


const int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN);
decode_results results;
Player player1(3, 100, 5, 25);
 
void setup()
{
   Serial.begin(9600);
   irrecv.enableIRIn();
}
 
void loop()
{
   if (irrecv.decode(&results))
   {
      Serial.println("Disparo!!");
      irrecv.resume();
      player1.substractHealth();
      player1.substractMunition();
      Serial.println(player1.getHealth());
      Serial.println(player1.getMunition());
      Serial.println(player1.getLife());
      delay(1000);
   }
}