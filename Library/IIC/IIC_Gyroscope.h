/**
 * @(#)File:           $RCSfile: IIC_Gyroscope.h $
 * @(#)Version:        $Revision: 0.1 $ 
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with Gyroscopeses over the I2C bus.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _IIC_GYROSCOPE_H
#define _IIC_GYROSCOPE_H

// Include files
#include "IIC.h"
#include <Wire.h>

/**
 * Select the correct Gyroscope that will be on the I2C
 * bus. It is critical that the correct device is selected
 * in order to have the correct registers and settings available.
 */
#define L3G4200D                        // Default

#ifdef  L3G4200D                        // Start L3G4200D

#define GYRO_IIC_READ_ID                0xD2    // Read ID
#define GYRO_IIC_WRITE_ID               0xD3    // Write ID
#define GYRO_IIC_7BIT                   GYRO_IIC_READ_ID >> 1  

//      List of all registers for ADXL345
#define GYRO_DEVICE_ID                  0x0F    // (WHO_AM_I)    R    Device ID
#define GYRO_CONTROL_1                  0x20    // (CTRL_REG1)    R/W    Control Register 1
#define GYRO_CONTROL_2                  0x21    // (CTRL_REG2)    R/W    Control Register 2
#define GYRO_CONTROL_3                  0x22    // (CTRL_REG3)    R/W    Control Register 3
#define GYRO_CONTROL_4                  0x23    // (CTRL_REG4)    R/W    Control Register 4
#define GYRO_CONTROL_5                  0x24    // (CTRL_REG5)    R/W    Control Register 5
#define GYRO_REFERENCE                  0x25    // (REFERENCE)    R/W    Reference
#define GYRO_OUT_TEMP                   0x26    // (OUT_TEMP)    R    Temperature Data
#define GYRO_STATUS                     0x27    // (STATUS_REG)    R    Status Register
#define GYRO_DATA_X0                    0x28    // (DATAX0)      R    X-axis data LSB
#define GYRO_DATA_X1                    0x29    // (DATAX1)      R    X-axis data MSB
#define GYRO_DATA_Y0                    0x2A    // (DATAY0)      R    Y-axis data LSB
#define GYRO_DATA_Y1                    0x2B    // (DATAY1)      R    Y-axis data MSB
#define GYRO_DATA_Z0                    0x2C    // (DATAZ0)      R    Z-axis data LSB
#define GYRO_DATA_Z1                    0x2D    // (DATAZ1)      R    Z-axis data MSB
#define GYRO_FIFO_CONTROL               0x2E    // (FIFO_CTRL_REG)  R/W    FIFO Control Register
#define GYRO_FIFO_SOURCE                0x2F    // (FIFO_SRC_REG)  R    FIFO Source Register
#define GYRO_INT1_CONFIG                0x30    // (INT1_CFG)    R/W    Interupt 1 Config
#define GYRO_INT1_SOURCE                0x31    // (INT1_SRC)    R    Interupt 1 Source
#define GYRO_INT1_TSH_XH                0x32    // (INT1_TSH_XH)  R/W    Interupt 1 TSH X MSB
#define GYRO_INT1_TSH_XL                0x33    // (INT1_TSH_XL)  R/W    Interupt 1 TSH X LSB
#define GYRO_INT1_TSH_YH                0x34    // (INT1_TSH_YH)  R/W    Interupt 1 TSH Y MSB
#define GYRO_INT1_TSH_YL                0x35    // (INT1_TSH_YL)  R/W    Interupt 1 TSH Y LSB
#define GYRO_INT1_TSH_ZH                0x36    // (INT1_TSH_ZH)  R/W    Interupt 1 TSH Z MSB
#define GYRO_INT1_TSH_ZL                0x37    // (INT1_TSH_ZL)  R/W    Interupt 1 TSH Z LSB
#define GYRO_INT1_DURATION              0x38    // (INT1_DURATION)  R/W    Interupt 1 Duration

//      Control Register 1
#define GYRO_CONTROL_1_DR_800           0xC0    // Data Rate 800 Hz
#define GYRO_CONTROL_1_DR_400           0x80    // Data Rate 400 Hz
#define GYRO_CONTROL_1_DR_200           0x40    // Data Rate 200 Hz
#define GYRO_CONTROL_1_DR_100           0x00    // Data Rate 100 Hz
#define GYRO_CONTROL_1_BW_110           0x30    // Cut-off between 25   @100Hz and 110 @800Hz
#define GYRO_CONTROL_1_BW_50            0x20    // Cut-off between 25   @100Hz and  50 @800Hz
#define GYRO_CONTROL_1_BW_35            0x10    // Cut-off between 25   @100Hz and  35 @800Hz
#define GYRO_CONTROL_1_BW_30            0x00    // Cut-off between 12.5 @100Hz and  30 @800Hz
#define GYRO_CONTROL_1_PD               0x08    // Power down mode: 0 down,    1 normal
#define GYRO_CONTROL_1_ZEN              0x04    // Z axis enable:  0 disabled, 1 normal
#define GYRO_CONTROL_1_YEN              0x02    // Y axis enable:  0 disabled, 1 normal
#define GYRO_CONTROL_1_XEN              0x01    // X axis enable:  0 disabled, 1 normal

//      Control Register 2
#define GYRO_CONTROL_2_HPM_NORMAL_HP    0x30
#define GYRO_CONTROL_2_HPM_REFERENCE    0x20
#define GYRO_CONTROL_2_HPM_NORMAL       0x10
#define GYRO_CONTROL_2_HPM_AUTORESET    0x00
#define GYRO_CONTROL_2_HPCF9            0x09
#define GYRO_CONTROL_2_HPCF8            0x08
#define GYRO_CONTROL_2_HPCF7            0x07
#define GYRO_CONTROL_2_HPCF6            0x06
#define GYRO_CONTROL_2_HPCF5            0x05
#define GYRO_CONTROL_2_HPCF4            0x04
#define GYRO_CONTROL_2_HPCF3            0x03
#define GYRO_CONTROL_2_HPCF2            0x02
#define GYRO_CONTROL_2_HPCF1            0x01
#define GYRO_CONTROL_2_HPCF0            0x00

//      Control Register 3
#define GYRO_CONTROL_3_INIT1            0x80
#define GYRO_CONTROL_3_BOOT             0x40
#define GYRO_CONTROL_3_LACTIVE          0x20
#define GYRO_CONTROL_3_OD               0x10
#define GYRO_CONTROL_3_DRDY             0x08
#define GYRO_CONTROL_3_WTM              0x04
#define GYRO_CONTROL_3_ORUN             0x02
#define GYRO_CONTROL_3_EMPTY            0x01

//      Control Register 4
#define GYRO_CONTROL_4_BDU              0x80    // Block Data Update
#define GYRO_CONTROL_4_BLE              0x40    // Big/Little Endian Data Select
#define GYRO_CONTROL_4_FS3              0x30    // 2000 dps
#define GYRO_CONTROL_4_FS2              0x20    // 2000 dps
#define GYRO_CONTROL_4_FS1              0x10    // 500 dps
#define GYRO_CONTROL_4_FS0              0x00    // 250 dps
#define GYRO_CONTROL_4_ST4              0x06    // Self test 0(-)
#define GYRO_CONTROL_4_ST1              0x02    // Self test 0(+)
#define GYRO_CONTROL_4_ST0              0x00    // Normal
#define GYRO_CONTROL_4_SIM              0x01    // SPI Serial Interface Mode

//      Control Register 5
#define GYRO_CONTROL_5_BOOT             0x80
#define GYRO_CONTROL_5_FIFO_EN          0x40
#define GYRO_CONTROL_5                  0x20
#define GYRO_CONTROL_5_HPEN             0x10
#define GYRO_CONTROL_5_INT1_SEL3        0x0C
#define GYRO_CONTROL_5_INT1_SEL2        0x08
#define GYRO_CONTROL_5_INT1_SEL1        0x04
#define GYRO_CONTROL_5_INT1_SEL0        0x00
#define GYRO_CONTROL_5_OUT_SEL3         0x03
#define GYRO_CONTROL_5_OUT_SEL2         0x02
#define GYRO_CONTROL_5_OUT_SEL1         0x01
#define GYRO_CONTROL_5_OUT_SEL0         0x00

//      Standard Operational Modes
#define GYRO_MODE                       GYRO_CONTROL_1
#define GYRO_MODE_NORMAL                GYRO_CONTROL_1_PD | GYRO_CONTROL_1_ZEN | GYRO_CONTROL_1_YEN | GYRO_CONTROL_1_XEN
#define GYRO_MODE_SLEEP                 GYRO_CONTROL_1_PD
#define GYRO_MODE_DISABLE               0x00


#endif                                  // End L3G4200D

namespace IIC {

    /**
     * The Gyroscope class is defined to simplify
     * the process of reading the gyroscope of a 
     * project. The class is designed to return the 
     * current gyroscope data of the unit. 
     */
    class Gyroscope : public IIC {
        public:

            /**
             * Default constructor. This function defines
             * the address variable based on the predefined
             * constants.
             */
            Gyroscope();

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
