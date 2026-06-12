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
  intake Intake(intakeMotors);
  Intake.startIntake();
  drive Drive(3.25, 4.0/3, 84, 22, 20.7, leftDrive, rightDrive, PORT1);
  Drive.turnAndDriveToPoint(96, 48,2,0.4,0.1,0,1,1,4,0);
  wait(0.5,sec);
  Intake.stopIntake();
  Drive.turnAndDriveToPoint(81,60,2,0.4,0.1,0,1,1,4,0 );
  Intake.extake();
  

  //(84,22)



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
  
  drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, PORT1);
  intake Intake(intakeMotors);
  Intake.startIntake();
  Chassis.driveDistance(28, 1, 1, 4, 0);
  wait(0.5,sec);
  Chassis.turnAngle(-65, 5 , 0.42, 0, 0);
  Intake.stopIntake();
  Chassis.driveDistance(14, 1, 2, 4, 0);
  Chassis.turnAngle(-10, 5 , 0.42, 0, 0);
  Intake.extake();
  wait(2, sec);
  Chassis.driveDistance(-40, 1, 2, 4, 0);
  Chassis.turnAngle(-210, 3 , 0.42, 0, 0);
  Intake.startIntake();
  Chassis.driveDistance(13, 1, 2, 4, 0);
  Chassis.turnAngle(75, 5, 0.42, 0, 0);
  Chassis.driveDistance(10, 0.5, 2, 4, 0);
  wait(1,sec);
  Intake.stopIntake();
  hoodPiston.set(false);
  Chassis.driveDistance(-30, 1, 2, 4, 0);
}