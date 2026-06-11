#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "lift.h"
#include "util.h"
#include "autons.h"

using namespace vex;

void rightAuton() {

  Controller.Screen.clearLine(3);
  Controller.Screen.setCursor(3, 1);
  Controller.Screen.print("start auton");

  drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, PORT1);
  intake Intake(intakeMotors);
  
  Intake.startIntake();
  Chassis.driveDistance(24, 1, 4, 4, 0);
  Chassis.turnAngle(-90, 5 , 0.42, 0, 0);
  Intake.stopIntake();
  hoodPiston.set(false);

  // Chassis.driveDistance(24, 1, 1, 0, 0.1);
  // Intake.startIntake();
  // Chassis.turnAngle(90);
  // Chassis.turnAngle(-90);
  // wait(2, sec);
  // Intake.stopIntake();
  // Chassis.driveDistance(-24);


}



void leftAuton() {
  
  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}