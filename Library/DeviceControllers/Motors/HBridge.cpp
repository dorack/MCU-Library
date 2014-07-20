/**
 * @(#)File:           $RCSfile: HBridge.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/07/01 12:00:00 $
 * @(#)Purpose:        HBridge Controller class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "HBridge.h"

// Full base constructor for the HBridge.
DeviceControllers::HBridge::HBridge(uint8_t i1, uint8_t i2, uint8_t c) {
    pin1 = i1;
    pin2 = i2;
    pinc = c;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    if (c < 255) {
        pinMode(c, OUTPUT);
    }
    enable();
}

// Turns on the first and off the second state. This is the typical configuration for forward movement.
void DeviceControllers::HBridge::forward() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

// Turns off the first and on the second state. This is the typical configuration for backward movement.
void DeviceControllers::HBridge::reverse() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

// Stops and Eisables the device.
void DeviceControllers::HBridge::disable() {
    stop();
    if (pinc != 255) {
        digitalWrite(pinc, LOW);
    }
}

// Enables and stops the device.
void DeviceControllers::HBridge::enable() {
    if (pinc != 255) {
        digitalWrite(pinc, HIGH);
    }
    stop();
}

// Halts the device to prevent it from moving.
void DeviceControllers::HBridge::stop() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
}
