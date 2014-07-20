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

#define SERVO_LOWER     20
#define SERVO_UPPER     180

class ServoCustom : public Servo {
    public:
        
        /**
         * Steps the servo motor one step 
         * 
         * @param int dir       direction to move
         * @param int tol       required minimal difference to move
         * @param int inc       value to increment by
         */
        int move(int dir, int tol);
        
        /**
         * Steps the servo motor one step 
         *
         * @param int dir       direction to move
         * @param int tol       required minimal difference to move
         */
        int move(int dir, int tol, int inc);
};

#endif