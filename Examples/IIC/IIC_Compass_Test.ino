
#include <Wire.h> //I2C Arduino Library
#include "IIC_Compass.h"

IIC::Compass comp;

void setup() {
    //Initialize Serial and I2C communications
    Serial.begin(9600);
    Wire.begin();
    comp.init();
}

void loop() {
    //Print out values of each axis
    Serial.print("x: ");
    Serial.print(comp.getX());
    Serial.print("  y: ");
    Serial.print(comp.getY());
    Serial.print("  z: ");
    Serial.println(comp.getZ());

    delay(250);
}
