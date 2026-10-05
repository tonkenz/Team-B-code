#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "lift.h"
#include "util.h"
#include "autons.h"
#include "drive.h"

using namespace vex;

void rightAuton() {
  //ten point
    // drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, PORT1);
  // Chassis.driveDistance(-5, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(6, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(-7, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(8, 0.25, 0.5, 0.01, 0.05);

  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
            //40 point PID
  // Chassis.driveDistance(-5, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(6, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(-7, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(8, 0.25, 0.5, 0.01, 0.05);
  // Chassis.turnAngle(-45, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(23, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(false);
  // Chassis.driveDistance(-2, 0.25, 0.5, 0.01, 0.05);
  // Chassis.turnAngle(44, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(true);
  // Chassis.turnAngle(180, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(false);
  // Chassis.turnAngle(42, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(true);
  // Chassis.turnAngle(180, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(false);
  
}

void leftAuton() {
            //ten point x and y
  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
          //ten point pid
  // drive Chassis(3.25, 5.0/3, leftDrive, rightDrive, PORT10);
  // Chassis.driveDistance(-5, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(6, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(-7, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(8, 0.25, 0.5, 0.01, 0.05);
            //40 point pid
  // drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, PORT10);
  // Chassis.driveDistance(-5, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(6, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(-7, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(8, 0.25, 0.5, 0.01, 0.05);
  // Chassis.turnAngle(45, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(23, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(false);
  // Chassis.driveDistance(-2, 0.25, 0.5, 0.01, 0.05);
  // Chassis.turnAngle(-44, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(true);
  // Chassis.turnAngle(180, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(false);
  // Chassis.turnAngle(-42, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(true);
  // Chassis.turnAngle(180, 0.25, 0.5, 0.01, 0.05);
  // Chassis.driveDistance(20, 0.25, 0.5, 0.01, 0.05);
  // ClawPiston.set(false);
  
  // drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  
} 


void skillsAuton() {

  drive Chassis(3.25, 5.0/3, 0, 0, 45, leftDrive, rightDrive, PORT1);

  //ten point
  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
}
  //Use functions to create a programming skills routine