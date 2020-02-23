#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup()
{
  pinMode(13,1);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    String x="";
    String y="Turn LED OFF";
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      x=((String)(char*)buf);
      x.trim();
      Serial.println(x+ " :"+x.length());   
       if(x=="Turn LED ON!")
       {
        Serial.println("true ");
        digitalWrite(13,1);
        }
        else
        {
          digitalWrite(13,0);
          }
          
    }
    
}
