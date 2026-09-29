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
  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
}

void leftAuton() {
            //ten point x and y
  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
            //ten point pid
  drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, PORT1);
  drive driveDistance(24, 0.25, 0.5, 0.01, 0.05);
  //void driveDistance(double distance, double tolerance, double kP, double kI, double kD);
            //40 point pid
  // drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  
}

void skillsAuton() {
  //ten point
  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
}
  //Use functions to create a programming skills routine