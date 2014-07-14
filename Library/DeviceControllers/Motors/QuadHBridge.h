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
	class DualHBridge {
		public:
			QuadHBridge() {};
			QuadHBridge(uint8_t li1, uint8_t li2, uint8_t li3, uint8_t li4, uint8_t ri1, uint8_t ri2, uint8_t ri3, uint8_t ri4, uint8_t lc1=255, uint8_t lc2=255, uint8_t rc1=255, uint8_t rc2=255);
			void InitLeft(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t c1=255, uint8_t c2=255);
			void InitRight(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t c1=255, uint8_t c2=255);
			void forward();
			void reverse();
			void turnRight();
			void turnLeft();
			void slideRight();
			void slideLeft();
			void disable();
			void enable();
			void stop();

			DualHBridge right;
			DualHBridge left;
	};
}
#endif
