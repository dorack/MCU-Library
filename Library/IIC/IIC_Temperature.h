/**
 * @(#)File:           $RCSfile: IIC_Temperature.h $
 * @(#)Version:        $Revision: 0.1 $ 
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with Temperatureses over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _IIC_TEMPERATURE_H
#define _IIC_TEMPERATURE_H

// Include files
#include "IIC.h"
#include <Wire.h>

/**
 * Select the correct Temperature that will be on the I2C
 * bus. It is critical that the correct device is selected
 * in order to have the correct registers and settings available.
 */
#define BMP085                          // Default

#ifdef  BMP085                          // Start BMP085

#define TEMP_IIC_READ_ID                0xEF    // Read ID
#define TEMP_IIC_WRITE_ID               0xEE    // Write ID
#define TEMP_IIC_7BIT                   TEMP_IIC_READ_ID >> 1

//    Control Registers
#define TEMP_TEMPERATURE                0x2E
#define TEMP_PRESSURE_0                 0x34
#define TEMP_PRESSURE_1                 0x74
#define TEMP_PRESSURE_2                 0xB4
#define TEMP_PRESSURE_3                 0xF4

//    Over Sampling Settings
#define TEMP_OSS_LOW                    0x00
#define TEMP_OSS_NORMAL                 0x01
#define TEMP_OSS_HIGH                   0x02
#define TEMP_OSS_ULTRA_HIGH             0x03


//    Calibration Registers
#define TEMP_CALIBRATION_AC1            0xAA
#define TEMP_CALIBRATION_AC2            0xAC
#define TEMP_CALIBRATION_AC3            0xAE
#define TEMP_CALIBRATION_AC4            0xB0
#define TEMP_CALIBRATION_AC5            0xB2
#define TEMP_CALIBRATION_AC6            0xB4
#define TEMP_CALIBRATION_B1             0xB6
#define TEMP_CALIBRATION_B2             0xB8
#define TEMP_CALIBRATION_MB             0xBA
#define TEMP_CALIBRATION_MC             0xBC
#define TEMP_CALIBRATION_MD             0xBE

//    Read Registers
#define  TEMP_DATA_UT                   0xF6
#define  TEMP_DATA_UP                   0x34

//    Mode Settings
//#define TEMP_NORMAL                                             
//#define TEMP_SLEEP                                              
//#define TEMP_DIABLE                                             

#endif                                  // End BMP085

namespace IIC {

    /**
     * The Temperature class is defined to simplify
     * the process of reading the temperature and 
     * air pressure of a project. The class is designed 
     * to return the temperature in Celsius and the
     * pressure in Pa. 
     */
    class Temperature : public IIC {
        public:
            
            /**
             * Default constructor. This function defines
             * the address variable based on the predefined
             * constants.
             */
            Temperature();
        
            /**
             * init function enables and establishes the default
             * functionality of the device based on the normal
             * mode.
             */
            void init();
            
            /**
             * Default Calibration function for the temperature
             * and barometric pressure sensor.
             */
            void calibrate();
            
            /**
             * getTemperature function processes the sensor
             * readings to calculate the current temperature
             * in Celsius.
             * 
             * @return 
             */
            short getTemperature();
            
            /**
             * getPressure function processes the sensor
             * readings to calculate the current pressure
             * in Pa. If divided by 0.01 the reading is in
             * minibars.
             * 
             * @return 
             */
            long getPresure();
        protected:
            
            //  Calibration Variables
            int ac1, ac2, ac3, b1, b2, mb, mc, md;
            unsigned int ac4, ac5, ac6;
            long b5;
            
            //  OSS offset value
            unsigned char OSS;
            
            /**
             * readUT returns the Unaltered Temperature of 
             * the sensor.
             * 
             * @return 
             */
            long readUT();
            
            /**
             * readUP returns the Unaltered Pressure of
             * the sensor.
             * 
             * @return 
             */
            unsigned long readUP();
    };
};
#endif
