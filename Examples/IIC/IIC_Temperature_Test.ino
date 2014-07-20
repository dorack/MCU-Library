#include <Wire.h>
#include "IIC_Temperature.h"
IIC::Temperature temp;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    temp.init();
}

void loop() {
    Serial.print("Temperature: ");
    Serial.print(int(temp.getTemperature() *0.1), DEC);
    Serial.println(" deg C");
    Serial.print("Pressure: ");
    Serial.print(temp.getPresure(), DEC);
    Serial.println(" Pa");
    Serial.println();
    delay(1000);
}


