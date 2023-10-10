#define DHTTYPE DHT11
#define DHTPIN 16

#include <Wire.h>
#include "rgb_lcd.h"
#include "DHT.h"

DHT dht(DHTPIN, DHTTYPE);
rgb_lcd lcd;

const int TouchPin=17;

void setup() 
{
    dht.begin();
    lcd.begin(16, 2);
    lcd.setRGB(0, 0, 0);
    pinMode(TouchPin, INPUT);
}

void loop() 
{
    if(digitalRead(TouchPin)==1)
    {
        float humidity = dht.readHumidity();  
        float temperature = dht.readTemperature();
        
        lcd.display();
        lcd.setRGB(0, 255, 0);
        
        lcd.setCursor(0,0);
        lcd.print("Hum: ");
        lcd.print(humidity);
        lcd.setCursor(0,1);
        lcd.print("Temp: ");
        lcd.print(temperature);
        
        delay(5000);
        
        lcd.noDisplay();
        lcd.setRGB(0, 0, 0);

    }
}
