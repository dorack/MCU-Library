/**
 * @(#)File:           $RCSfile: HBridge.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/07/01 12:00:00 $
 * @(#)Purpose:        HBridge Controller class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _HBRIDGE_H
#define _HBRIDGE_H

#include "Arduino.h"
#include <inttypes.h>

namespace DeviceControllers {

    /**
     *	The HBridge class handles the functionality for controlling the
     *	reversable flow of DC current through a specalized IC. The IC 
     *	can vary but the basic configuration is either 2 or 3 pins to
     *	control the flow for the rotating motor.
     */
    class HBridge {
        public:

            /**
             * Default Constructor
             */
            HBridge() {};

            /**
             * Full HBridge constructor
             * 
             * @param i1    an1
             * @param i2    an2
             * @param c     control
             */
            HBridge(uint8_t i1, uint8_t i2, uint8_t c = 255);

            /**
             * Places motor in forward movement
             */
            void forward();

            /**
             * Places motor in reverse movement
             */
            void reverse();

            /**
             * Disables motor and controller
             */
            void disable();

            /**
             * Enables motor and controller
             */
            void enable();

            /**
             * Stops the motor
             */
            void stop();

        protected:
            // Variables
            uint8_t pin1;
            uint8_t pin2;
            uint8_t pinc;
    };
}
#endif
