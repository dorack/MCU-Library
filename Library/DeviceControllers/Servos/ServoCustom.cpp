/**
 * @(#)File:           $RCSfile: ServoCustom.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/05/01 12:00:00 $
 * @(#)Purpose:        Customization and expantion of the Servo class
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#include "ServoCustom.h" // include Servo library

// Moves the motor by specified amount
int ServoCustom::move(int dir, int tol, int inc) {
    int value = this->read();
    if (-1 * tol > dir || dir > tol) {
        if (dir > 0) {
            value = inc - value;
            if (value < SERVO_LOWER) {
                value = SERVO_LOWER;
            }
        } else if (dir < 0) {
            value = inc + value;
            if (value > SERVO_UPPER) {
                value = SERVO_UPPER;
            }
        }
        this->write(value);
    }
}

// Moves the motor by a single step
int ServoCustom::move(int dir, int tol) {
    move(dir, tol, 1);
}
