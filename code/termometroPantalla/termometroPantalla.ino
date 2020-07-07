
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
//Conectamos el sensor al pin 2
#define DHTPIN 2     


#define DHTTYPE DHT11   // DHT 22 )en su caso sustituir)
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
//Código preparado para OLED DE 0.96
dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
display.display();
delay(2000);
display.clearDisplay();
}

void loop() {
    display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(1,1);
  //Humedad relativa
  float h = dht.readHumidity();
//Temperatura
float t = dht.readTemperature();
    if (isnan(h) || isnan(t) ) {
    display.println("¡ERROR DE SENSOR!");
    display.display();
    delay(2000);
    return;
  }else{
    display.clearDisplay();
 
    display.print(t,1);
    display.print(" ");
    //Imprimir el carácter "º"
    display.print((char)247);
    display.print("C");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setCursor(1,0);

    display.print(h,1);
    display.println(" %");
    display.display();
    delay(2000);
  }
  
}
