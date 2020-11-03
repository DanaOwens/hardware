/*
Transmitter Code
Date: November 1, 2020
*/

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

// @TODO: Figure out how we're reading data from sensor
// Reading from a file or having a program pass in value

RH_ASK driver;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    char buf[30];
    const char *temp = "0"; //Would read thermistor here
    const char *dist = "0"; //Would read proximity here
    strcpy(buf,temp);
    strcat(buf,dist);
    driver.send((uint8_t *)buf, strlen(buf));
    driver.waitPacketSent();
    delay(1000);
    
}