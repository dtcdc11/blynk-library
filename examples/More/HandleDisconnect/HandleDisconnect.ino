/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * 
 * This example shows how to keep WiFi connection on ESP8266.
 * 
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";


int lastConnectionAttempt = millis();
int connectionDelay = 5000; // try to reconnect every 5 seconds

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  // check WiFi connection:
  if(WiFi.status() != WL_CONNECTED)
  {
    // (optional) "offline" part of code
    
    // check delay:
    if(millis() - lastConnectionAttempt >= connectionDelay)
    {
      lastConnectionAttempt = millis();

      // attempt to connect to Wifi network:
      if (pass && strlen(pass)) 
      {
        WiFi.begin((char*)ssid, (char*)pass);
      } 
      else 
      {
        WiFi.begin((char*)ssid);
      }
    }
  }
  else
  {
    Blynk.run();
  }
}
