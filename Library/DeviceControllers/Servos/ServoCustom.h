/**
 * @(#)File:           $RCSfile: ServoCustom.h $
 * @(#)Version:        $Revision: 0.1 $
 * @(#)Last changed:   $Date: 2014/05/01 12:00:00 $
 * @(#)Purpose:        Customization and expantion of the Servo class.
 * @(#)Author:         S Handschuh
 * @(#)Copyright:      (C) 2014
 * @(#)License:        MIT
 */
#ifndef _SERVO_CUSTOM_H
#define _SERVO_CUSTOM_H

#include "Arduino.h"
#include <Servo.h> // include Servo library

#define SERVO_LOWER		20
#define SERVO_UPPER		180

class ServoCustom : public Servo {
	public:
		int move(int dir, int tol);
		int move(int dir, int tol, int inc);
};

#endif