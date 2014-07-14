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
			DualHBridge() {};
			DualHBridge(uint8_t li1, uint8_t li2, uint8_t ri1, uint8_t ri2, uint8_t lc=255, uint8_t rc=255);
			void forward();
			void reverse();
			void turnRight();
			void turnLeft();
			void disable();
			void enable();
			void stop();

			HBridge right;
			HBridge left;
	};
}
#endif
