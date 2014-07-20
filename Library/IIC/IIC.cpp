/**
 * @(#)File:           $RCSfile: IIC.cpp $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C control wrapper. The initial configuration is from the 
 *                       Arduino library, however, additional containers could 
 *                       becreated and substituted to replace the IIC class.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT 
 */
#include "IIC.h"

// Default constructor
IIC::IIC::IIC() {
}

// Returns the reading lowbyte first in an int
int IIC::IIC::getInt(int lowbit, short bytes) {
    int out = 0;
    Wire.beginTransmission(address); // transmit to device
    Wire.write(lowbit);
    Wire.endTransmission();
    Wire.requestFrom((int) address, bytes);
    while (Wire.available() < bytes);
    for (int i = 0; i < bytes; i++) {
        if (i == 0) {
            out |= Wire.read();
        } else {
            out |= Wire.read() << (8 * i);
        }
    }
    return out;
}

// Returns the reading highbyte first in an int
int IIC::IIC::getIntRev(int lowbit, short bytes) {
    int out = 0;
    Wire.beginTransmission(address); // transmit to device
    Wire.write(lowbit);
    Wire.endTransmission();
    Wire.requestFrom((int) address, bytes);
    while (Wire.available() < bytes);
    for (int i = bytes-1; i >= 0; i--) {
        if (i == 0) {
            out |= Wire.read();
        } else {
            out |= Wire.read() << (8 * i);
        }
    }
    return out;
}

// Writes a gyro register
void IIC::IIC::writeReg(short reg, short value) {
    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

// Reads a gyro register
short IIC::IIC::readReg(short reg) {
    short value;
    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom((int) address, 1);
    value = Wire.read();
    Wire.endTransmission();

    return value;
}

