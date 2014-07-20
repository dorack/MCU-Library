/**
 * @(#)File:           $RCSfile: IIC_Compass.cpp $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with compasses over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "IIC_Compass.h"

// Default constructor
IIC::Compass::Compass() {
    address = COMP_IIC_7BIT;
}

// initializes the device 
void IIC::Compass::init() {
    writeReg(COMP_MODE, COMP_MODE_NORMAL);
}

// Returns X-axis value
short IIC::Compass::getX() {
    return getInt(COMP_DATA_X1);
}

// Returns Y-axis value
short IIC::Compass::getY() {
    return getInt(COMP_DATA_Y1);
}

// Returns Z-axis value
short IIC::Compass::getZ() {
    return getInt(COMP_DATA_Z1);
}
