/**
 * @(#)File:           $RCSfile: IIC_Accelerometer.cpp $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with accelerometers over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "IIC_Accelerometer.h"

// Default constructor
IIC::Accelerometer::Accelerometer() {
    address = ACC_IIC_7BIT_ID;
}

// initializes the device 
void IIC::Accelerometer::init() {
    writeReg(ACC_POWER_CONTROL, ACC_MODE_NORMAL);
}

// Returns raw X-axis value
short IIC::Accelerometer::getX() {
    return getInt(ACC_DATA_X0);
}

// Returns gravity value of the X-axis
double IIC::Accelerometer::getXg() {
    return getX() / 256.0;
}

// Returns raw Y-axis value
short IIC::Accelerometer::getY() {
    return getInt(ACC_DATA_Y0);
}

// Returns gravity value of the Y-axis
double IIC::Accelerometer::getYg() {
    return getY() / 256.0;
}

// Returns raw Z-axis value
short IIC::Accelerometer::getZ() {
    return getInt(ACC_DATA_Z0);
}

// Returns gravity value of the Z-axis
double IIC::Accelerometer::getZg() {
    return getZ() / 256.0;
}

