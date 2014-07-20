# MCU-Library

MCU Library will provide compact support for devices attached via buss and direct connection to controller pins.

The MCU-Library project is due to the lack of solid driver files provided by the community and manufacturers. Most of the examples are rudimentary and cover only the minimum necessary to operate the device. This is a problem because all of the code can become muddled if everything is in the same function or file. By breaking the components down to individual classes it makes it easier to modify and maintain the project.

## Specifications

* Platform:     Arduino (AVR)
* Language:     C/C++
* Difficulty:   Intermediate
* Requirements: Arduino (AVR) hardware and compiler

## Library

* Device Drivers
  * The DeviceDrivers namespace includes hardware specific driver code
  * Some devices will or might include HBridge and LED grids
* IIC
  * IIC namespace contains the prototypes and classes to use the IIC bus
  * Includes Accelerometer, Magnetic Compass, Gyroscope, and Temperature sensors

## Revisions

### Version 0.2

* IIC Namespace
* IIC, Accelerometer, Compass, Gyroscope, and Temperature classes
* Examples of Accelerometer, Compas, Gyroscope, and Temperature classes
* Support for ADXL345, HMC5883L, L3G4200D, and BMP085 added

### Version 0.1

* DeviceDrivers Namespace
* HBridge, DualHBridge and QuadHBridge classes

## Author

* Author: Stanley Handschuh
* Project: Robotics, Aerospace, and Astrospace
* About: The MCU-Library project is due to the lack of solid driver files provided by the community and manufacturers. Most of the examples are rudimentary and cover only the minimum necessary to operate the device. This is a problem because all of the code can become muddled if everything is in the same function or file. By breaking the components down to individual classes it makes it easier to modify and maintain the project.


