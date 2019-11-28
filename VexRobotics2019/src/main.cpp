/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\kate                                             */
/*    Created:      Wed Nov 27 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10           
// IntakeRight          motor         19              
// IntakeLeft           motor         20              
// IntakeArmTiltLeft    motor         17              
// IntakeArmTiltRight   motor         18              
// BlockRampTilt        motor         5               
// FrontBump            bumper        A               
// BackBump             bumper        B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool TouchBlock() {
  
  bool touched = FrontBump.pressing();
  // Try three times
  for (int i = 0; i < 3; i++) {
    if (touched) break;
    Drivetrain.setDriveVelocity(20,percent);
    Drivetrain.driveFor(2,inches);
    touched = FrontBump.pressing();
    Drivetrain.setDriveVelocity(75,percent);
  }
  return touched;
}

int main()  {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Move towards the blocks
  Drivetrain.driveFor(24,inches);
 
  // If touched then pick up the blocks
  bool blockTouch = TouchBlock();

  if (blockTouch) {
    Drivetrain.setDriveVelocity(20,percent);
    IntakeLeft.spinFor(0.5,turns);
    IntakeRight.spinFor(0.5,turns); 
    Drivetrain.setDriveVelocity(75,percent);

  //If does not touch block
  } else { 
    Drivetrain.setTimeout(15,seconds);
  }

  // Continue towards the next few blocks
  Drivetrain.driveFor(24,inches);
 
  // Check if touched, and if so then pick up the blocks
  blockTouch = TouchBlock();

  if (blockTouch) {
    Drivetrain.setDriveVelocity(20,percent);
    IntakeLeft.spinFor(0.5,turns);
    IntakeRight.spinFor(0.5,turns); 
    Drivetrain.setDriveVelocity(75,percent);
  
  // If does not touch blocks
  } else
    Drivetrain.turnFor(90, degrees);
    Drivetrain.driveFor(36, inches);
    Drivetrain.turnFor(90,degrees);
    Drivetrain.driveFor(24,inches);
    BlockRampTilt.spinToPosition(0,degrees);
    Drivetrain.driveFor(-5,inches);

  // Continue turning and moving forwards
  Drivetrain.turnFor(90,degrees);
  Drivetrain.driveFor(24,inches);
  Drivetrain.turnFor(90,degrees);
  Drivetrain.driveFor(24,inches);
  
  // Check and take blocks
  blockTouch = TouchBlock();

  if (blockTouch) {
    Drivetrain.setDriveVelocity(20,percent);
    IntakeLeft.spinFor(0.5,turns);
    IntakeRight.spinFor(0.5,turns); 
    Drivetrain.setDriveVelocity(75,percent);
  
  // If robot does not get the blocks
  } else
  Drivetrain.turnFor(-90,degrees);
  Drivetrain.driveFor(12,inches);
  Drivetrain.turnFor(90,degrees);
  Drivetrain.driveFor(12,inches);
  BlockRampTilt.spinToPosition(0,degrees);
  Drivetrain.driveFor(5,inches);

  // Move robot back to base
  Drivetrain.turnFor(-90,degrees);
  Drivetrain.driveFor(12,inches);
  Drivetrain.turnFor(90,degrees);
  Drivetrain.driveFor(12,inches);
  
  // Drop the blocks
  BlockRampTilt.spinToPosition(0,degrees);
  Drivetrain.driveFor(5,inches);
 
 }
  

