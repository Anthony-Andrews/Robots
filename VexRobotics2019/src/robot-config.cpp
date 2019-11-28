#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 130, mm, 1);
motor IntakeRight = motor(PORT19, ratio18_1, false);
motor IntakeLeft = motor(PORT20, ratio18_1, false);
motor IntakeArmTiltLeft = motor(PORT17, ratio18_1, false);
motor IntakeArmTiltRight = motor(PORT18, ratio18_1, false);
motor BlockRampTilt = motor(PORT5, ratio18_1, false);
bumper FrontBump = bumper(Brain.ThreeWirePort.A);
bumper BackBump = bumper(Brain.ThreeWirePort.B);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}