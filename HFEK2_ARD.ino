/***************************************************************************
 * Precision Microdrives
 * ARDUINO HAPTICS for Haptic Feedback Evaluation Kit 2 (HFEK2) and demos
 * by: Tristan Cool
 * September 2019 
 * Arduino UNO
***************************************************************************/

//*************************** INCLUDE **************************************//
#define __PROG_TYPES_COMPAT__
#include <avr/pgmspace.h>

#include <SPI.h>
//#include <mpr121.h>
#include <i2c.h>

// Debug
#include "debug.h"

// Include our headers
#include "Metro.h"
#include "motor.h"

// MPR121 touchpad
#include "Adafruit_MPR121.h"

// Init timer for 2s, and auto-reset when we get a positive check
Metro timer( 2000, 1 );
Motor motor = Motor();

//*************************** WIRING  **************************************//
/* PMD Haptic Feedback Evaluation Kit (HFEK) in Developer Mode
 * MPR121
 * Joystick
 * Buttons
 * TFT screen
 */

//*************************** VARIABLES **************************************//

//MPR121 touchpad
//TODO

//Joystick 
//TODO

//Buttons
//TODO

//TFT Screen
//TODO

// ******** FUNCTION PROTOTYPES ***********


//*************************** SETUP **************************************//
void setup()
{
  //setup Serial
  Serial.begin( 9600 );
  Serial.println(F("PRECISION MICRODRIVES - HFEK2_PMD DEMO"));
  //Serial.print( F("FreeMem=") );
  //Serial.println( freeRAM() );

  //init DRV
  setupPins();
  i2cInit( 200 );
  
  //Set up the motor
  motor.selectMotor(3); //LRA (solenoid)
  motor.autoCalibrate();

  //Ensure any time for calibration is ignored.
  timer.reset();

} //end:SETUP

//*************************** LOOP **************************************//
void loop()
{
  //TODO
} //end:LOOP


//*************************** FUNCTIONS **************************************//

void setupPins()
{
    pinMode( DRV_2605_EN,       OUTPUT );   // Output for DRV2605 Enable
    pinMode( PWM_OUT,           OUTPUT );   // Output for PWM
    pinMode( SRC_SEL,           OUTPUT );   // HIGH = DRV, LOW = MOS 
    pinMode( GRIP_SEL,          OUTPUT );   // LOW = Haptic Grip Connected
    pinMode( LRA_SEL,           OUTPUT );   // LOW = Haptic Shield LRA Connected
    pinMode( ERM_SEL,           OUTPUT );   // LOW = Haptic Shield ERM Connected

    pinMode( MOTOR_PIN_0,       OUTPUT );   // Motor select 1
    pinMode( MOTOR_PIN_1,       OUTPUT );   // Motor select 2
    
    digitalWrite( PWM_OUT,      LOW );      // PWM output low
    digitalWrite( SRC_SEL,      HIGH );     // Select DRV
    digitalWrite( GRIP_SEL,     HIGH  );    // Select none 
    digitalWrite( ERM_SEL,      HIGH  );    // Select none
    digitalWrite( LRA_SEL,      HIGH  );    // Select none 

    //TODO - Joystick
    //TODO - MPR121
    
} //end:setupPins
