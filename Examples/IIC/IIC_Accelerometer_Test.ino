#include <Wire.h>
#include "IIC_Accelerometer.h"

IIC::Accelerometer acc;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    delay(100);
    acc.init();
}

void loop() {
    Serial.print("X= ");
    Serial.print(acc.getXg());
    Serial.print("       ");
    Serial.print("Y= ");
    Serial.print(acc.getYg());
    Serial.print("       ");
    Serial.print("Z= ");
    Serial.print(acc.getZg());
    Serial.println("  ");
    delay(200);
}




