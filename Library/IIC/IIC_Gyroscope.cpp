/**
 * @(#)File:           $RCSfile: IIC_Gyroscope.cpp $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with Gyroscopees over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "IIC_Gyroscope.h"

// Default constructor
IIC::Gyroscope::Gyroscope() {
    address = GYRO_IIC_7BIT;
}

// initializes the device 
void IIC::Gyroscope::init() {
    writeReg(GYRO_CONTROL_1, GYRO_MODE_NORMAL);
}

// Returns X-axis value
short IIC::Gyroscope::getX() {
    return getInt(GYRO_DATA_X0 | (1 << 7));
}

// Returns Y-axis value
short IIC::Gyroscope::getY() {
    return getInt(GYRO_DATA_Y0 | (1 << 7));
}

// Returns Z-axis value
short IIC::Gyroscope::getZ() {
    return getInt(GYRO_DATA_Z0 | (1 << 7));
}


