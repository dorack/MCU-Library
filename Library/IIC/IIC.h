/**
 * @(#)File:           $RCSfile: IIC.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/06/18 12:00:00 $
 * @(#)Purpose:        I2C control wrapper. The initial configuration is from the 
 *                       Arduino library, however, additional containers could 
 *                       be created and substituted to replace the IIC class.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _IIC_H
#define _IIC_H
#include <Wire.h> 

namespace IIC {

    /**
     * The IIC class is a class designed to be extended for specific 
     * hardware specifications. However, it could be instantiated 
     * for generic hardware usage instead of being extended for a 
     * predefined device.
     */
    class IIC {
        public:
            /**
             * Default Constructor for the IIC class
             */
            IIC();
        protected:
            /**
             * getInt function will return the bit stream from the
             * IIC device where the data is received in the order of 
             * least significant byte first.
             * 
             * @param lowbit    This is the first byte to be read
             * @param bytes     This is the number of bytes to read
             * @return 
             */
            int getInt(int lowbit, short bytes = 2);

            /**
             * getInt function will return the bit stream from the
             * IIC device where the data is received in the order of 
             * most significant byte first.
             * 
             * @param lowbit    This is the first byte to be read
             * @param bytes     This is the number of bytes to read
             * @return 
             */
            int getIntRev(int lowbit, short bytes = 2);
            
            /**
             * writeReg will send a single write command to the
             * specified register with the provided value.
             * 
             * @param reg       Register to be modified
             * @param value     Value to write
             */
            void writeReg(short reg, short value);
            
            /**
             * readReg will request the value of the specified
             * register
             * 
             * @param reg       Register to be read
             * @return          Value of the register
             */
            short readReg(short reg);
            
            /**
             * address is the IIC address of the device. Depending
             * on the hardware it could use a 7 or 8 bit address. 
             * The 8bit address includes the read/write bit where
             * the 7bit address is pushed down to remove it.
             * 
             * 8bit address:    11101111
             * 7bit address:    01110111        (8bit >> 1)
             */
            uint8_t address;
    };
}
#endif
