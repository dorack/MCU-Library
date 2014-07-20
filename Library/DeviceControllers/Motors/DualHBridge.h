/**
 * @(#)File:           $RCSfile: DualHBridge.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/07/01 12:00:00 $
 * @(#)Purpose:        DualHBridge Controller class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _DUAL_HBRIDGE_H
#define _DUAL_HBRIDGE_H

#include "Arduino.h"
#include <inttypes.h>
#include "HBridge.h"


namespace DeviceControllers {

    /**
     *	The DualHBridge class handles the functionality for managing
     *	2 HBridge controllers in tandom. This is a standard configuration
     *	on many HBridge IC devices.
     */
    class DualHBridge {
        public:

            /**
             * Default constructor
             */
            DualHBridge() {
            };

            /**
             * Full Dual HBridge constructor
             * 
             * @param li1   left an1
             * @param li2   left an2
             * @param ri1   right an1
             * @param ri2   right an2
             * @param lc    left control
             * @param rc    right control
             */
            DualHBridge(uint8_t li1, uint8_t li2, uint8_t ri1, uint8_t ri2, uint8_t lc = 255, uint8_t rc = 255);

            /**
             * Places all motors in forward movement
             */
            void forward();

            /**
             * places all motors in reverse movement
             */
            void reverse();

            /**
             * Places right motor in reverse and left in forward
             */
            void turnRight();

            /**
             * Places left motor in reverse and right in forward
             */
            void turnLeft();

            /**
             * Disables all motors and controller
             */
            void disable();

            /**
             * Enables all motors and controller
             */
            void enable();

            /**
             * Stops all motors from moving
             */
            void stop();

        protected:
            // Variables
            HBridge right;
            HBridge left;
    };
}
#endif
