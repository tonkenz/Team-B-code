// src/robot-config.cpp
#include "robot-config.h"

using namespace vex;

//Configuration!

/* 
 * Reminders: 
 * Make sure that all your ports are different and correct! 
 * Make sure all of your motor + piston names are different and not confusing.
 * If it seems like some of your motors are running against eachother in the drivetrain, try switching around the true/false
*/

//DON'T CHANGE THE NAMES OF THE MOTORS OR SENSORS. Changing the ports to reflect your robot is ok.

brain Brain;
controller Controller(controllerType::primary);
motor LB(PORT8, ratio6_1, true); //Left Back Motor
motor LM(PORT9, ratio18_1, false); //Left Middle Motor
motor LF(PORT10, ratio6_1, true); //Left Front Motor
motor RB(PORT1, ratio6_1, false); //Right Back Motor
motor RM(PORT2, ratio18_1, true); //Right Middle Motor 
motor RF(PORT3, ratio6_1, false); //Right Front Motor


motor_group leftDrive(LB, LM, LF);
motor_group rightDrive(RB, RM, RF);
motor_group LiftMotors(Lift1, Lift2);


motor Lift1(PORT10, gearSetting::ratio6_1, true); //Lift motor
motor Lift2(PORT1, gearSetting::ratio6_1, false); //Lift motor

digital_out ClawPiston(Brain.ThreeWirePort.H);
digital_out SingleActingPiston(Brain.ThreeWirePort.B);

// motor intakeMotor(PORT14, ratio18_1, false);
// motor middleIntakeMotor(PORT13, ratio18_1, true);
// motor  bottomIntakeMotor(PORT12, ratio18_1, false); 

// motor_group intakeMotors(intakeMotor, middleIntakeMotor, bottomIntakeMotor);

inertial InertialSensor(PORT5);

motor toggle(PORT8);

// optical OpticalSensor(PORT21);

void vexcodeInit() {
  InertialSensor.calibrate();
  ClawPiston.set(false); // retracted
  SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    task::sleep(100);
  }
  Controller.rumble("._._._._._._._._.");
}