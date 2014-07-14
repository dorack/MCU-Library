/**
 * @(#)File:           $RCSfile: QuadHBridge.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/07/01 12:00:00 $
 * @(#)Purpose:        QuadHBridge Controller class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "QuadHBridge.h"

namespace DeviceControllers {

	/**
	 *	Full base constructor for the QuadHBridge
	 *	
	 *	@param uint8_t li1	-	Left HBridge Odd or first control pin
	 *	@param uint8_t li2	-	Left HBridge Even or second control pin
	 *	@param uint8_t ri1	-	Right HBridge Odd or first control pin
	 *	@param uint8_t ri2	-	Right HBridge Even or second control pin
	 *	@param uint8_t lc	-	Left HBridge Master control for the IC
	 *	@param uint8_t rc	-	Right HBridge Master control for the IC
	 */
	QuadHBridge(uint8_t li1, uint8_t li2, uint8_t li3, uint8_t li4, uint8_t ri1, uint8_t ri2, uint8_t ri3, uint8_t ri4, uint8_t lc1=255, uint8_t lc2=255, uint8_t rc1=255, uint8_t rc2=255);
		InitLeft(li1, li2, li3, li4, lc1, lc2);
		InitRight(ri1, ri2, ri3, ri4, rc1, rc2);
	}

	void InitLeft(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t c1=255, uint8_t c2=255) {
		left = DualHBridge::DualHBridge(i1, i2, i3, i4, c1, c2);
	}

	void InitRight(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t c1=255, uint8_t c2=255) {
		right = DualHBridge::DualHBridge(i1, i2, i3, i4, c1, c2);
	}

	/**
	 *	Turns both motors into a forward movement.
	 */
	void QuadHBridge::forward() {
		left.forward();
		right.forward();
	}

	/**
	 *	Turns both motors into a backword movement.
	 */
	void QuadHBridge::reverse() {
		left.reverse();
		right.reverse();
	}
		
	/**
	 *	Configures the two controllers to enable a 
	 *	right hand turn.
	 */
	void QuadHBridge::turnRight() {
		left.reverse();
		right.forward();
	}

	/**
	 *	Configures the two controllers to enable a 
	 *	left hand turn.
	 */
	void QuadHBridge::turnLeft() {
		left.forward();
		right.reverse();
	}

	/**
	 *	Configures the two controllers to enable a 
	 *	right hand turn.
	 */
	void QuadHBridge::slideRight() {
		left.turnRight();
		right.turnRight();
	}

	/**
	 *	Configures the two controllers to enable a 
	 *	left hand turn.
	 */
	void QuadHBridge::slideLeft() {
		left.turnLeft();
		right.turnLeft();
	}

	/**
	 *	Disables both controllers.
	 */
	void QuadHBridge::disable() {
		left.disable();
		right.disable();
	}

	/**
	 *	Enables both controllers.
	 */
	void QuadHBridge::enable() {
		left.enable();
		right.enable();
	}

	/**
	 *	Stops both controllers.
	 */
	void QuadHBridge::stop() {
		left.stop();
		right.stop();
	}
}
