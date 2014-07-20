/**
 * @(#)File:           $RCSfile: QuadHBridge.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/07/01 12:00:00 $
 * @(#)Purpose:        QuadHBridge Controller class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _QUAD_HBRIDGE_H
#define _QUAD_HBRIDGE_H

#include "Arduino.h"
#include <inttypes.h>
#include "DualHBridge.h"


namespace DeviceControllers {

    /**
     *	The DualHBridge class handles the functionality for managing
     *	2 HBridge controllers in tandom. This is a standard configuration
     *	on many HBridge IC devices.
     */
    class QuadHBridge {
        public:

            /**
             * Default constructor
             * @return 
             */
            QuadHBridge() {};

            /**
             * Full Quad HBridge constructor
             * 
             * @param li1   left an1
             * @param li2   left an2
             * @param li3   left an3
             * @param li4   left an4
             * @param ri1   right an1
             * @param ri2   right an2
             * @param ri3   right an3
             * @param ri4   right an4
             * @param lc1   left control1
             * @param lc2   left control2
             * @param rc1   right control1
             * @param rc2   right control2
             */
            QuadHBridge(uint8_t li1, uint8_t li2, uint8_t li3, uint8_t li4, uint8_t ri1, uint8_t ri2, uint8_t ri3, uint8_t ri4, uint8_t lc1 = 255, uint8_t lc2 = 255, uint8_t rc1 = 255, uint8_t rc2 = 255);

            /**
             * InitLeft initializes the left controller
             * 
             * @param i1    left an1
             * @param i2    left an2
             * @param i3    left an3
             * @param i4    left an4
             * @param c1    left control1
             * @param c2    left control2
             */
            void InitLeft(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t c1 = 255, uint8_t c2 = 255);

            /**
             * InitRight initializes the right controller
             * 
             * @param i1    right an1
             * @param i2    right an2
             * @param i3    right an3
             * @param i4    right an4
             * @param c1    right control1
             * @param c2    right control2
             */
            void InitRight(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t c1 = 255, uint8_t c2 = 255);

            /**
             * forward places all motors in forward movement
             */
            void forward();

            /**
             * reverse places all motors in reverse movement
             */
            void reverse();

            /**
             * turnRight places the right motors in reverse
             * and the left in forward.
             */
            void turnRight();

            /**
             * turnLeft places the left motors in reverse
             * and the right in forward
             */
            void turnLeft();

            /**
             * slideRight will place the motors in the 
             * correct directions to move the unit laterally
             * to the right
             */
            void slideRight();

            /**
             * slideLeft will place the motors in the
             * correct directions to move the unit laterally
             * to the left;
             */
            void slideLeft();

            /**
             * disable disables all motors and controllers
             */
            void disable();

            /**
             * enable enables all motors and controllers
             */
            void enable();

            /**
             * stop will halt motion of all motors
             */
            void stop();

        protected:
            // Variables
            DualHBridge right;
            DualHBridge left;
    };
}
#endif
