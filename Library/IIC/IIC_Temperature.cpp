/**
 * @(#)File:           $RCSfile: IIC_Temperature.cpp $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with Temperaturees over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "IIC_Temperature.h"

// Default constructor
IIC::Temperature::Temperature() {
    address = TEMP_IIC_7BIT;
}

// Initializes the device 
void IIC::Temperature::init() {
    calibrate();
    OSS = TEMP_OSS_LOW;
}

// Retrieves the calibration values
void IIC::Temperature::calibrate() {
    ac1 = getIntRev(TEMP_CALIBRATION_AC1);
    ac2 = getIntRev(TEMP_CALIBRATION_AC2);
    ac3 = getIntRev(TEMP_CALIBRATION_AC3);
    ac4 = getIntRev(TEMP_CALIBRATION_AC4);
    ac5 = getIntRev(TEMP_CALIBRATION_AC5);
    ac6 = getIntRev(TEMP_CALIBRATION_AC6);
    b1 = getIntRev(TEMP_CALIBRATION_B1);
    b2 = getIntRev(TEMP_CALIBRATION_B2);
    mb = getIntRev(TEMP_CALIBRATION_MB);
    mc = getIntRev(TEMP_CALIBRATION_MC);
    md = getIntRev(TEMP_CALIBRATION_MD);
}

// Returns the temperature in Celsius
short IIC::Temperature::getTemperature() {
    long x1, x2;
    unsigned int ut = readUT();
    x1 = (((long) ut - (long) ac6)*(long) ac5) >> 15;
    x2 = ((long) mc << 11) / (x1 + md);
    b5 = x1 + x2;
    return ((b5 + 8) >> 4);
}

// Returns the pressure in Pa
long IIC::Temperature::getPresure() {
    long x1, x2, x3, b3, b6, p;
    unsigned long b4, b7, up = readUP();

    b6 = b5 - 4000;
    // Calculate B3
    x1 = (b2 * (b6 * b6) >> 12) >> 11;
    x2 = (ac2 * b6) >> 11;
    x3 = x1 + x2;
    b3 = (((((long) ac1)*4 + x3) << OSS) + 2) >> 2;
    
    // Calculate B4
    x1 = (ac3 * b6) >> 13;
    x2 = (b1 * ((b6 * b6) >> 12)) >> 16;
    x3 = ((x1 + x2) + 2) >> 2;
    b4 = (ac4 * (unsigned long) (x3 + 32768)) >> 15;
    
    b7 = ((unsigned long) (up - b3) * (50000 >> OSS));
    if (b7 < 0x80000000)
        p = (b7 << 1) / b4;
    else
        p = (b7 / b4) << 1;

    x1 = (p >> 8) * (p >> 8);
    x1 = (x1 * 3038) >> 16;
    x2 = (-7357 * p) >> 16;
    p += (x1 + x2 + 3791) >> 4;
    return p;
}

// Returns the unaltered temperature
long IIC::Temperature::readUT() {
    // Write 0x2E into Register 0xF4
    // This requests a temperature reading
    writeReg(TEMP_PRESSURE_3, TEMP_TEMPERATURE);

    // Wait at least 4.5ms
    delay(5);

    // Read two bytes from registers 0xF6 and 0xF7
    return getIntRev(TEMP_DATA_UT);
}

// Returns the unaltered pressure
unsigned long IIC::Temperature::readUP() {
    unsigned int msb, lsb, xlsb;
    unsigned long up = 0;

    // Write 0x34+(OSS<<6) into register 0xF4
    // Request a pressure reading w/ oversampling setting
    writeReg(TEMP_PRESSURE_3, (TEMP_DATA_UP + (OSS << 6)));

    // Wait for conversion, delay time dependent on OSS
    delay(2 + (3 << OSS));

    // Read register 0xF6 (MSB), 0xF7 (LSB), and 0xF8 (XLSB)
    Wire.beginTransmission(address);
    Wire.write(TEMP_DATA_UT);
    Wire.endTransmission();
    Wire.requestFrom((int) address, (int) 3);

    // Wait for data to become available
    while (Wire.available() < 3);
    msb = Wire.read();
    lsb = Wire.read();
    xlsb = Wire.read();

    up = (((unsigned long) msb << 16) | ((unsigned long) lsb << 8) | (unsigned long) xlsb) >> (8 - OSS);

    return up;
}
