#include <Wire.h>
#include "IIC_Gyroscope.h"
IIC::Gyroscope gyro;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    gyro.init();
}

void loop() {
    Serial.print("G ");
    Serial.print("X: ");
    Serial.print((int) gyro.getX());
    Serial.print(" Y: ");
    Serial.print((int) gyro.getY());
    Serial.print(" Z: ");
    Serial.println((int) gyro.getZ());

    delay(100);
}
