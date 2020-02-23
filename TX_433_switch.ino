#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
  pinMode(7,0);
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  int x=digitalRead(7);
    const char *msg1 = "Turn LED ON!";
    const char *msg2 = "Turn LED OFF";
    if(x==1)
    {
    driver.send((uint8_t *)msg1, strlen(msg1));
    }
    else
    {
      driver.send((uint8_t *)msg2, strlen(msg2));
      }
    driver.waitPacketSent();
    delay(1000);
}
