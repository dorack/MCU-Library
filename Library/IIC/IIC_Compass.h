/**
 * @(#)File:           $RCSfile: IIC_Compass.h $
 * @(#)Version:        $Revision: 0.1 $ 
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with Compassses over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _IIC_COMPASS_H
#define _IIC_COMPASS_H

// Include files
#include "IIC.h"
#include <Wire.h>

/**
 * Select the correct Compass that will be on the I2C
 * bus. It is critical that the correct device is selected
 * in order to have the correct registers and settings available.
 */
#define HMC5883L                       // Default

#ifdef  HMC5883L                       // Start HMC5883L

#define COMP_IIC_READ_ID               0x3D    // Read ID
#define COMP_IIC_WRITE_ID              0x3C    // Write ID
#define COMP_IIC_7BIT                  COMP_IIC_READ_ID >> 1  

//    List of all registers for ADXL345
#define COMP_CONFIG_A                  0x00    // (CONFIG_A)    R/W    Configuration Register A
#define COMP_CONFIG_B                  0x01    // (CONFIG_B)    R/W    Configuration Register B
#define COMP_MODE                      0x02    // (MODE)      R/W    Mode Register
#define COMP_DATA_X1                   0x03    // (DATAX1)      R    X-axis data MSB
#define COMP_DATA_X0                   0x04    // (DATAX0)      R    X-axis data LSB
#define COMP_DATA_Y1                   0x05    // (DATAY1)      R    Y-axis data MSB
#define COMP_DATA_Y0                   0x06    // (DATAY0)      R    Y-axis data LSB
#define COMP_DATA_Z1                   0x07    // (DATAZ1)      R    Z-axis data MSB
#define COMP_DATA_Z0                   0x08    // (DATAZ0)      R    Z-axis data LSB
#define COMP_STATUS_REGISTER           0x09    // (STATUS)      R    Status Register
#define COMP_ID_A                      0x0A    // (ID_A)      R    Identification Register A
#define COMP_ID_B                      0x0B    // (ID_B)      R    Identification Register B
#define COMP_ID_C                      0x0C    // (ID_C)      R    Identification Register C

//    Configuration Register A
#define COMP_CONFIG_A_CRA7             0x80    // No current functionality
#define COMP_CONFIG_A_MA1              0x40    // Select number of samples averaged (1 to 8) per
#define COMP_CONFIG_A_MA0              0x20    // measurement output 00 = 1(default); 01 = 2; 10 = 4; 11 = 8;
#define COMP_CONFIG_A_DO2              0x10    // Data Output Rate Bits. These bits set the rate at
#define COMP_CONFIG_A_DO1              0x08    // which data is written to all three data output registers.
#define COMP_CONFIG_A_DO0              0x04    // 
#define COMP_CONFIG_A_MS1              0x02    // Measurement Configuration Bits. These bits define the measurement flow of the device, 
#define COMP_CONFIG_A_MA0              0x01    // specificly whether or not to incorporate an applied bias into the measurement.

//    Typical Data Output Rate (Hz)
#define COMP_CONFIG_A_DO_RESERVED      0x1C    // Output Data Rate Reserved for future
#define COMP_CONFIG_A_DO_75            0x18    // Output Data Rate  75Hz
#define COMP_CONFIG_A_DO_30            0x14    // Output Data Rate  30Hz
#define COMP_CONFIG_A_DO_15            0x10    // Output Data Rate  15Hz    (Default)
#define COMP_CONFIG_A_DO_750           0x0C    // Output Data Rate   7.50Hz
#define COMP_CONFIG_A_DO_300           0x08    // Output Data Rate   3.00Hz
#define COMP_CONFIG_A_DO_150           0x04    // Output Data Rate   1.50Hz
#define COMP_CONFIG_A_DO_075           0x00    // Output Data Rate   0.75Hz

//    Measurement Mode
#define COMP_CONFIG_A_MS_RESERVED      0x03    // Measurement Mode Reserved for future
#define COMP_CONFIG_A_MS_NEG           0x02    // Negative bias configuraiton for X, Y, Z axis. In this configuration, a negative current is forced across the resistive load for all three axis.
#define COMP_CONFIG_A_MS_POS           0x01    // Positive bias configuraiton for X, Y, Z axis. In this configuration, a positive current is forced across the resistive load for all three axis.
#define COMP_CONFIG_A_MS_NORM          0x00    // Normal measurement configuration (Default). In normal measurement configuration the device follows normal measurement flow. The positive and negative pins of the resistive load are left floating and high impedance.

//    Configuration Register A
#define COMP_CONFIG_B_GN2              0x80    // Gain Configuration Bits. These bits configure the gain for 
#define COMP_CONFIG_B_GN1              0x40    // the device. The gain configuration is common for all channels.
#define COMP_CONFIG_B_GN0              0x20    // 
#define COMP_CONFIG_B_CRB4_0           0x00    // These bits must be cleared for correct operation.

//      Gain Configuration Bits                   Recommended     |      Gain     | Resolution | Output Range
//                                             Sensor Field Range |  (LSb/Gauss)  |  (mG/LSb)  |
#define COMP_CONFIG_B_GN_230           0x1C    // � 8.10 Ga       |      230      |    4.35    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_330           0x18    // � 5.60 Ga       |      330      |    3.03    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_390           0x14    // � 4.70 Ga       |      390      |    2.56    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_440           0x10    // � 4.00 Ga       |      440      |    2.27    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_660           0x0C    // � 2.50 Ga       |      660      |    1.52    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_820           0x08    // � 1.90 Ga       |      820      |    1.22    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_1090          0x04    // � 1.30 Ga       | 1090(default) |    0.92    | 0xF800�0x07FF (-2048�2047 )
#define COMP_CONFIG_B_GN_1370          0x00    // � 0.88 Ga       |     1370      |    0.73    | 0xF800�0x07FF (-2048�2047 ) 

//    Mode Register
#define COMP_MODE_HS                   0x80    // Set this pin to enabled High Speed 12C, 3400kHz
#define COMP_MODE_MD1                  0x02    // Mode Select Bits. These bits select 
#define COMP_MODE_MD0                  0x01    // the operation mode of this device

//    Measurement Mode
#define COMP_MODE_DISABLE              0x03    // Idle Mode. Device is placed in idle mode.
#define COMP_MODE_SLEEP                0x02    // Idle Mode. Device is placed in idle mode.
#define COMP_MODE_SINGLE               0x01    // Single-Measurement Mode (Default).
#define COMP_MODE_NORMAL               0x00    // Continuous-Measurement Mode.

#endif                                 // End HMC5883L

namespace IIC {
    
    /**
     * The Compass class is defined to simplify
     * the process of reading the magnetic compass
     * direction of a project. The class is designed 
     * to return the compass direction of the unit. 
     */
    class Compass : public IIC {
        public:
            
            /**
             * Default constructor. This function defines
             * the address variable based on the predefined
             * constants.
             */
            Compass();

            /**
             * init function enables and establishes the default
             * functionality of the device based on the normal
             * mode.
             */
            void init();

            /**
             * getX returns the raw acceleration data from
             * the device along the X-Axis.
             * 
             * @return 
             */
            short getX();

            /**
             * getY returns the raw acceleration data from
             * the device along the Y-Axis.
             * 
             * @return 
             */
            short getY();

            /**
             * getZ returns the raw acceleration data from
             * the device along the Z-Axis.
             * 
             * @return 
             */
            short getZ();
        protected:
    };
}
#endif
