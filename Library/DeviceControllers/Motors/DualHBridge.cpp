/**
 * @(#)File:           $RCSfile: DualHBridge.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/07/01 12:00:00 $
 * @(#)Purpose:        DualHBridge Controller class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "DualHBridge.h"

namespace DeviceControllers {

	/**
	 *	Full base constructor for the DualHBridge
	 *	
	 *	@param uint8_t li1	-	Left HBridge Odd or first control pin
	 *	@param uint8_t li2	-	Left HBridge Even or second control pin
	 *	@param uint8_t ri1	-	Right HBridge Odd or first control pin
	 *	@param uint8_t ri2	-	Right HBridge Even or second control pin
	 *	@param uint8_t lc	-	Left HBridge Master control for the IC
	 *	@param uint8_t rc	-	Right HBridge Master control for the IC
	 */
	DualHBridge::DualHBridge(uint8_t li1, uint8_t li2, uint8_t ri1, uint8_t ri2, uint8_t lc, uint8_t rc) {
		left = HBridge(li1, li2, lc);
		right = HBridge(ri1, ri2, rc);
	}

	/**
	 *	Turns both motors into a forward movement.
	 */
	void DualHBridge::forward() {
		left.forward();
		right.forward();
	}

	/**
	 *	Turns both motors into a backword movement.
	 */
	void DualHBridge::reverse() {
		left.reverse();
		right.reverse();
	}
		
	/**
	 *	Configures the two controllers to enable a 
	 *	right hand turn.
	 */
	void DualHBridge::turnRight() {
		left.reverse();
		right.forward();
	}

	/**
	 *	Configures the two controllers to enable a 
	 *	left hand turn.
	 */
	void DualHBridge::turnLeft() {
		left.forward();
		right.reverse();
	}

	/**
	 *	Disables both controllers.
	 */
	void DualHBridge::disable() {
		left.disable();
		right.disable();
	}

	/**
	 *	Enables both controllers.
	 */
	void DualHBridge::enable() {
		left.enable();
		right.enable();
	}

	/**
	 *	Stops both controllers.
	 */
	void DualHBridge::stop() {
		left.stop();
		right.stop();
	}
}
