using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor IntakeRight;
extern motor IntakeLeft;
extern motor IntakeArmTiltLeft;
extern motor IntakeArmTiltRight;
extern motor BlockRampTilt;
extern bumper FrontBump;
extern bumper BackBump;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );