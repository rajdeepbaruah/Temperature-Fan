//Code Written By RAJDEEP BARUAH

#include <DHT.h>
#include <LiquidCrystal.h>

//Constants
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
 
 //Variables
 int fan=9, fan_speed;
 float hum;
 float temp;
 float temp_start=10;
 float temp_full=30;

 //LCD Object
 LiquidCrystal lcd(12,11,5,4,3,2);

 void setup()
 {
    Serial.begin(9600);
    dht.begin();
    lcd.begin(16, 2);
    pinMode(fan, OUTPUT);
  }

  void loop()
  {
      delay(2000);
      hum=dht.readHumidity();
      temp=dht.readTemperature();

      fan_speed=map(temp,temp_start,temp_full,0,255);
      analogWrite(9,min(255,fan_speed));
      Serial.print("Humidity:  ");
      Serial.print(hum);
      Serial.print("%, Temp:  ");
      Serial.print(temp);
      Serial.print("Celcius");

      lcd.setCursor(0,0);
      lcd.print("Weather");
      lcd.setCursor(1,1);
      lcd.print(temp);
      lcd.print("C");
      lcd.print(hum);
      lcd.print("%");

      delay(2000);
    }
    
