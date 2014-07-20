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

// Full base constructor for the DualHBridge
DeviceControllers::DualHBridge::DualHBridge(uint8_t li1, uint8_t li2, uint8_t ri1, uint8_t ri2, uint8_t lc, uint8_t rc) {
    left = HBridge(li1, li2, lc);
    right = HBridge(ri1, ri2, rc);
}

// Turns both motors into a forward movement.
void DeviceControllers::DualHBridge::forward() {
    left.forward();
    right.forward();
}

// Turns both motors into a backword movement.
void DeviceControllers::DualHBridge::reverse() {
    left.reverse();
    right.reverse();
}

// Configures the two controllers to enable a right hand turn.
void DeviceControllers::DualHBridge::turnRight() {
    left.reverse();
    right.forward();
}

// Configures the two controllers to enable a left hand turn.
void DeviceControllers::DualHBridge::turnLeft() {
    left.forward();
    right.reverse();
}

// Disables both controllers.
void DeviceControllers::DualHBridge::disable() {
    left.disable();
    right.disable();
}

// Enables both controllers.
void DeviceControllers::DualHBridge::enable() {
    left.enable();
    right.enable();
}

// Stops both controllers.
void DeviceControllers::DualHBridge::stop() {
    left.stop();
    right.stop();
}
