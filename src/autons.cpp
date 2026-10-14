#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "lift.h"
#include "util.h"
#include "autons.h"
#include "drive.h"

using namespace vex;
void rightAuton() {
  //20 point
    drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, LiftMotors, PORT14);
    lift lift(PORT10, PORT1, Brain.ThreeWirePort.H);
    Chassis.driveDistance(4, 0.1, 6, 0.001, 0.05);
    Chassis.driveDistance(-5, 0.1, 6, 0.001, 0.05);
    Chassis.driveDistance(5, 0.1, 6, 0.001, 0.05);
    Chassis.driveDistance(-48, 0.25, 2, 0.001, 0.001);
    Chassis.turnAngle(-50, 0.25, 2, 0.01, 0.0005);
    // LiftMotors.setVelocity(100, percent);
    // LiftMotors.spinFor(reverse, 300, degrees, false); 
    Chassis.driveDistance(37, 0.1, 5, 0.001, 0.05);
    ClawPiston.set(true);
    
    // Chassis.driveDistance(-5, 0.1, 5, 0.001, 0.05);
    // Chassis.turnAngle(-90, 0.5, 0.5, 0.001, 0.005);
    // Chassis.driveDistance(5, 0.1, 5, 0.001, 0.05);
    // ClawPiston.set(false);
    // Chassis.driveDistance(-5, 0.1, 5, 0.001, 0.05);
    // Chassis.turnAngle(90, 0.5, 0.6, 0.001, 0.005)
    // Chassis.driveDistance(5, 0.1, 5, 0.001, 0.05);
    // ClawPiston.set(true);


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
    drive Chassis(3.25, 4.0/3, leftDrive, rightDrive, LiftMotors, PORT14);

Chassis.driveDistance(-48, 0.25, 2, 0.01, 0.0005);
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

  //ten point
  /*drive Chassis(3.25, 4.0/3, 0, 0, 0, leftDrive, rightDrive, PORT1);
  Chassis.backwardsToPoint(0, 0, 0.25, 0.5, 0.01, 0.05, 0.25, 2, 0.05, 0.2);*/
}
  //Use functions to create a programming skills routine