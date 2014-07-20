/**
 * @(#)File:           $RCSfile: IIC_Accelerometer.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C controller expansion designed to operate with accelerometers over the I2C bus.
 * @(#)Author:         S Handschuh 
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _IIC_ACCELEROMETER_H
#define _IIC_ACCELEROMETER_H

// Include files
#include "IIC.h"
#include <Wire.h>

/**
 * Select the correct Accelerometer that will be on the I2C
 * bus. It is critical that the correct device is selected
 * in order to have the correct registers and settings available.
 */
#define ADXL345                        // Default


#ifdef  ADXL345                        // Start ADXL345

#define ACC_IIC_READ_ID                0xA7    // Read ID
#define ACC_IIC_WRITE_ID               0xA6    // Write ID
#define ACC_IIC_7BIT_ID                ACC_IIC_READ_ID >> 1

//      List of all registers for ADXL345
#define ACC_DEVICE_ID                  0x00    // (DEVID)      R    Device ID
#define ACC_TAP_THRESHOLD              0x1D    // (THRESH_TAP)    R/W    Tap Threshold
#define ACC_OFFSET_X                   0x1E    // (OFSX)      R/W    X-axis Offset
#define ACC_OFFSET_Y                   0x1F    // (OFSY)      R/W    Y-axis Offset
#define ACC_OFFSET_Z                   0x20    // (OFSZ)      R/W    Z-axis Offset
#define ACC_TAP_DURATION               0x21    // (DUR)      R/W    Tap Duration
#define ACC_TAP_LATENCY                0x22    // (Latent)      R/W    Tap Latency
#define ACC_TAP_WINDOW                 0x23    // (Window)      R/W    Tap Window
#define ACC_THRESH_ACT                 0x24    // (THRESH_ACT)    R/W    Activity threshhold
#define ACC_THRESH_INACT               0x25    // (THRESH_INACT)  R/W    Inactivity threshhold
#define ACC_TIME_INACT                 0x26    // (TIME_INACT)    R/W    Inactivity time
#define ACC_ACT_INACT_CONTROL          0x27    // (ACT_INACT_CTL)  R/W    Axis enable control for activity and inactivity detection
#define ACC_FF_THRESHOLD               0x28    // (THRESH_FF)    R/W    Free-fall threshold
#define ACC_FF_TIME                    0x29    // (TIME_FF)    R/W    Free-fall time
#define ACC_TAP_AXES                   0x2A    // (TAP_AXES)    R/W    Axis control for single tap/double tap
#define ACC_ACT_TAP_STATUS             0x2B    // (ACT_TAP_STATUS)  R    Source of single tap/double tap
#define ACC_BANDWIDTH_RATE             0x2C    // (BW_RATE)    R/W    Data rate and power mode control
#define ACC_POWER_CONTROL              0x2D    // (POWER_CTL)    R/W    Power and Control
#define ACC_INT_ENABLE                 0x2E    // (INT_ENABLE)    R/W    Interrupt enable control
#define ACC_INT_MAP                    0x2F    // (INT_MAP)    R/W    Interrupt mapping control
#define ACC_INT_SOURCE                 0x30    // (INT_SOURCE)    R    Source of interrupts
#define ACC_DATA_FORMAT                0x31    // (DATA_FORMAT)  R/W    Data format control
#define ACC_DATA_X0                    0x32    // (DATAX0)      R    X-Axis Data 0
#define ACC_DATA_X1                    0x33    // (DATAX1)      R    X-Axis Data 1
#define ACC_DATA_Y0                    0x34    // (DATAY0)      R    Y-Axis Data 0
#define ACC_DATA_Y1                    0x35    // (DATAY1)      R    Y-Axis Data 1
#define ACC_DATA_Z0                    0x36    // (DATAZ0)      R    Z-Axis Data 0
#define ACC_DATA_Z1                    0x37    // (DATAZ1)      R    Z-Axis Data 1
#define ACC_FIFO_CONTROL               0x38    // (FIFO_CTL)    R/W    FIFO Control
#define ACC_FIFO_STATUS                0x39    // (FIFO_STATUS)  R    FIFO status

//      Bandwidth rate settings. The value is to be used for the BANDWIDTH_RATE register
//      High speed bandwidth                         Rate  Power Mode
#define ACC_BANDWIDTH_RATE_LOW_POWER   0x10    // Low power mode enabled
#define ACC_BANDWIDTH_RATE_3200        0x0F    // Output Data Rate  3200Hz    H
#define ACC_BANDWIDTH_RATE_1600        0x0E    // Output Data Rate  1600Hz    H
#define ACC_BANDWIDTH_RATE_800         0x0D    // Output Data Rate   800Hz    H
#define ACC_BANDWIDTH_RATE_400         0x0C    // Output Data Rate   400Hz    H/L
#define ACC_BANDWIDTH_RATE_200         0x0B    // Output Data Rate   200Hz    H/L
#define ACC_BANDWIDTH_RATE_100         0x0A    // Output Data Rate   100Hz    H/L
#define ACC_BANDWIDTH_RATE_50          0x09    // Output Data Rate    50Hz    H/L
#define ACC_BANDWIDTH_RATE_25          0x08    // Output Data Rate    25Hz    H/L

//      Low speed bandwidth                            Rate  Power Mode
#define ACC_BANDWIDTH_RATE_125         0x07    // Output Data Rate 12.50Hz    H/L
#define ACC_BANDWIDTH_RATE_625         0x06    // Output Data Rate  6.25Hz    H
#define ACC_BANDWIDTH_RATE_313         0x05    // Output Data Rate  3.13Hz    H
#define ACC_BANDWIDTH_RATE_156         0x04    // Output Data Rate  1.56Hz    H
#define ACC_BANDWIDTH_RATE_078         0x03    // Output Data Rate  0.78Hz    H
#define ACC_BANDWIDTH_RATE_039         0x02    // Output Data Rate  0.39Hz    H
#define ACC_BANDWIDTH_RATE_020         0x01    // Output Data Rate  0.20Hz    H
#define ACC_BANDWIDTH_RATE_010         0x00    // Output Data Rate  0.10Hz    H

//      Active and Inactive Control values
#define ACC_ACT_INACT_CONTROL_ACT      0x80
#define ACC_ACT_INACT_CONTROL_ACT_X    0x40
#define ACC_ACT_INACT_CONTROL_ACT_Y    0x20
#define ACC_ACT_INACT_CONTROL_ACT_Z    0x10
#define ACC_ACT_INACT_CONTROL_INACT    0x08
#define ACC_ACT_INACT_CONTROL_INACT_X  0x04
#define ACC_ACT_INACT_CONTROL_INACT_Y  0x02
#define ACC_ACT_INACT_CONTROL_INACT_Z  0x01

//      Tap Axis Control values
#define ACC_TAP_AXES_SUPPRESS          0x08
#define ACC_TAP_AXES_X_AXIS            0x04
#define ACC_TAP_AXES_Y_AXIS            0x02
#define ACC_TAP_AXES_Z_AXIS            0x01

//      Power and Control settings
#define ACC_POWER_CONTROL_LINK         0x20
#define ACC_POWER_CONTROL_AUTO_SLEEP   0x10
#define ACC_POWER_CONTROL_MEASURE      0x08
#define ACC_POWER_CONTROL_SLEEP        0x04
#define ACC_POWER_CONTROL_WAKEUP_1     0x03
#define ACC_POWER_CONTROL_WAKEUP_2     0x02
#define ACC_POWER_CONTROL_WAKEUP_3     0x01
#define ACC_POWER_CONTROL_WAKEUP_8     0x00

//      Interrupt Enable/Map/Source Control
#define ACC_INT_DATA_READY             0x80
#define ACC_INT_SINGLE_TAP             0x40
#define ACC_INT_DOUBLE_TAP             0x20
#define ACC_INT_ACTIVITY               0x10
#define ACC_INT_INACTIVITY             0x08
#define ACC_INT_FREE_FALL              0x04
#define ACC_INT_WATERMARK              0x02
#define ACC_INT_OVERRUN                0x01

//      Data Format Control
#define ACC_DATA_FORMAT_SELF_TEST      0x80
#define ACC_DATA_FORMAT_SPI            0x40
#define ACC_DATA_FORMAT_INT_INVERT     0x20
#define ACC_DATA_FORMAT_FULL_RES       0x08
#define ACC_DATA_FORMAT_JUSTIFY        0x04
#define ACC_DATA_FORMAT_RANGE_16       0x03
#define ACC_DATA_FORMAT_RANGE_8        0x02
#define ACC_DATA_FORMAT_RANGE_4        0x01
#define ACC_DATA_FORMAT_RANGE_2        0x00

//      FIFO Control
#define ACC_FIFO_CONTROL_MODE_TRIGGER  0xC0
#define ACC_FIFO_CONTROL_MODE_STREAM   0x80
#define ACC_FIFO_CONTROL_MODE_FIFO     0x40
#define ACC_FIFO_CONTROL_MODE_BYPASS   0x00
#define ACC_FIFO_CONTROL_TRIGGER       0x20

//      Standard Mode Controls
#define ACC_MODE                       ACC_POWER_CONTROL
#define ACC_MODE_NORMAL                ACC_POWER_CONTROL_MEASURE
#define ACC_MODE_SLEEP                 ACC_POWER_CONTROL_AUTO_SLEEP
#define ACC_MODE_DISABLE               ACC_POWER_CONTROL_SLEEP

#endif                                 // End ADXL345

namespace IIC {

    /**
     * The Accelerometer class is defined to simplify
     * the process of reading the acceleration of a 
     * project. The class is designed to return the 
     * raw acceleration and the gravitational 
     * acceleration of the unit. 
     */
    class Accelerometer : public IIC {
        public:
            /**
             * Default constructor. This function defines
             * the address variable based on the predefined
             * constants.
             */
            Accelerometer();

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
             * getX returns the gravity acceleration data from
             * the device along the X-Axis.
             * 
             * @return 
             */
            double getXg();

            /**
             * getY returns the raw acceleration data from
             * the device along the Y-Axis.
             * 
             * @return 
             */
            short getY();

            /**
             * getY returns the gravity acceleration data from
             * the device along the Y-Axis.
             * 
             * @return 
             */
            double getYg();

            /**
             * getZ returns the raw acceleration data from
             * the device along the Z-Axis.
             * 
             * @return 
             */
            short getZ();

            /**
             * getZ returns the gravity acceleration data from
             * the device along the Z-Axis.
             * 
             * @return 
             */
            double getZg();
        protected:
    };
}
#endif
