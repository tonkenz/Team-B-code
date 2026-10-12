/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       katherinezeng                                             */
/*    Created:      5/27/2025, 10:30:19 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <chrono>
using namespace std::chrono;
#include "vex.h"
#include "robot-config.h"
#include "PID.h"
#include "autons.h"
#include "auton-selector.h"
#include "lift.h"
#include "util.h"
#include "drive.h"
#include "intake.h"

using namespace vex;
using namespace std;

// A global instance of competition
competition Competition;




//  //use mlm
// void mlmControl()
// {
//     if (mlmtrue)
//     {
//         DoubleActingPiston.set(true);
//     }
//     else
//     {
//         DoubleActingPiston.set(false);
//     }
// }

// mlm using one button
/*void usingmlm()
{
    auto now = steady_clock::now();
    auto durLastmlm = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastmlm).count();
    if (durLastmlm > 200)
    {
        mlmControl();
        mlmtrue = !mlmtrue;
        lastmlm = now;
    }
}*/

// void clampcontrol() {
//   if (clamptrue) {
//    mlmUse();
//   } else {
//    mlmAway();
//   }
//  }

//  void loading() {
//   auto now = steady_clock::now();
//   auto durlastloading = duration_cast<milliseconds>(now-lastclamp).count();
//   if (durlastloading > 100) {
//     clampcontrol();
//     clamptrue = !clamptrue;
//     lastclamp = now;
//   }
//  }




/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...


  vexcodeInit();
  autonSelector selector(1, 3);
  selector.chooseAuton();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
  switch (autonSelector::getSelectedAuton()) {

    case 1:
      rightAuton();
      break;

    case 2:
      leftAuton();
      break;

    case 3:
      skillsAuton();
      break;

    default:
      Brain.Screen.print("No selected");
      break;
  }


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool inauton = false;

// Drivetrain functions in functions.cpp


//Variables used in driver control
double intakeSpeed = 0;
bool buttonR1pressed = false;

// User control function
void usercontrol(void) {
  bool slowModeActive = false;

  while (true) {

    // ========== DRIVE CONTROL ========== //
    //arcade drive control
    double forward = Controller.Axis3.position() * 1; // forward/backward, change multiplier for sensitivity
    double turn = Controller.Axis1.position() * 1;
    
    // tank drive control
    // double forward = (Controller.Axis3.position() + Controller.Axis2.position()) / 2; // forward/backward, change multiplier for sensitivity
    // double turn = (Controller.Axis3.position() - Controller.Axis2.position()) / 2; // turning, change multiplier for sensitivity

    //single stick drive control
    // double forward = Controller.Axis3.position() * 1; // forward/backward, change multiplier for sensitivity
    // double turn = Controller.Axis4.position() * 1; 

    // Convert to voltage (+-12000 mV)
    double leftVoltage = (forward + turn) * 100;
    double rightVoltage = (forward - turn) * 100;

    // limmit :D
    if (leftVoltage > 12000)
        leftVoltage = 12000;
    if (leftVoltage < -12000)
        leftVoltage = -12000;
    if (rightVoltage > 12000)
        rightVoltage = 12000;
    if (rightVoltage < -12000)
        rightVoltage = -12000;
        
    // Drive motors (direction, side of dt, voltage units)
    leftDrive.spin(vex::forward, leftVoltage, voltageUnits::mV);
    rightDrive.spin(vex::forward, rightVoltage, voltageUnits::mV);

    // if (Controller.ButtonA.pressing()){
    //   intakeMotor.spin(forward, 80, percent);
    //   middleIntakeMotor.spin(forward, 80, percent);
    // }
    // else if (Controller.ButtonB.pressing()){
    //   intakeMotor.spin(reverse, 80, percent);
    //   middleIntakeMotor.spin(reverse, 80, percent);
    // }
    // else {
    //   intakeMotor.stop(hold);
    //   middleIntakeMotor.stop(hold);
    // }

    // // ========== TOGGLE ==========//
    // if (Controller.ButtonY.pressing()){
    //   toggle.spin(vex::forward, 9000, voltageUnits::mV);
    // }
    // else{
    //   toggle.stop(hold);
    // }
    // // ========== Lift CONTROL ========== //
    // // Hold down the R1 and R2 buttons to use the lift //
    if (Controller.ButtonL2.pressing()) {
      Lift1.spin(vex::forward, 9000, voltageUnits::mV);
      Lift2.spin(vex::forward, 9000, voltageUnits::mV);
    } 
    else if (Controller.ButtonL1.pressing()) {
      Lift1.spin(vex::reverse, 9000, voltageUnits::mV);
      Lift2.spin(vex::reverse, 9000, voltageUnits::mV);
    } 
    else {
      Lift1.stop(hold);
      Lift2.stop(hold);
    }

    // if (Controller.ButtonA.pressing()){
    //   ClawPiston.set(true);
    // }
    // else if (Controller.ButtonB.pressing()){
    //   ClawPiston.set(false);
    // }
    if(Controller.ButtonA.pressing()){
      ClawPiston.set(false);
    }
    else{
      ClawPiston.set(true);
    }

    // // ========== INTAKE ========== //

    // if (Controller.ButtonR1.pressing()){
    //   intakeMotor.spin(vex::forward, 12000, voltageUnits::mV);
    // }
    // else if (Controller.ButtonR2.pressing()){
    //   intakeMotor.spin(vex::reverse, 12000, voltageUnits::mV);
    // }
    // else{
    //   intakeMotor.stop(hold);
    // }
    // // Tap the L1 and L2 buttons to set the intake speed. Tap the same button again to stop //
    // if (Controller.ButtonL1.pressing() && intakeSpeed != 100 && !buttonL1Held) {
    //   intakeMotor.spin(forward, 100, percent);
    //   intakeSpeed = 100;
    //   buttonL1Held = true;
    // } 
    // else if(Controller.ButtonL1.pressing() && intakeSpeed == 100 && !buttonL1Held) {
    //   intakeMotor.stop(coast);
    //   intakeSpeed = 0;
    //   buttonL1Held = true;
    // }
    // else if (Controller.ButtonL2.pressing() && intakeSpeed != -100 && !buttonL2Held) {
    //   intakeMotor.spin(reverse, 100, percent);
    //   intakeSpeed = -100;
    //   buttonL2Held = true;
    // } 
    // else if (Controller.ButtonL2.pressing() && intakeSpeed == -100 && !buttonL2Held){
    //   intakeMotor.stop(coast);
    //   intakeSpeed = 0;
    //   buttonL2Held = true;
    // }

    // if(!Controller.ButtonL1.pressing()) {
    //   buttonL1Held = false;
    // }
    // if(!Controller.ButtonL2.pressing()) {
    //   buttonL2Held = false;
    // }
 
    // ========== COLOR SENSOR ========== //
    // color detectedColor = OpticalSensor.color();

    /*if (detectedColor == color::blue) {
      Brain.Screen.printAt(50, 50, "Blue Detected!");
    } 
    
    else if (detectedColor == color::red) {
      Brain.Screen.printAt(50, 50, "Red Detected!");
    } 
    
    else {
      Brain.Screen.printAt(50, 50, "No specific color detected.");
    }*/

    // double hue = OpticalSensor.hue();
    // double brightness = OpticalSensor.brightness();
    // Brain.Screen.printAt(50, 70, "Hue: %.2f", hue);
    // Brain.Screen.printAt(50, 90, "Brightness: %.2f", brightness);
    // Brain.Screen.clearScreen();

    // ========== PNEUMATICS ========== //
    // Use the X button to toggle the piston position //
    // if (Controller.ButtonR1.pressing() && !buttonR1pressed) {
    //   ClawPiston.set(!ClawPiston.value());
    //   buttonR1pressed = true;
    // } 
    // else if (!Controller.ButtonR1.pressing()) {
    //   buttonR1pressed = false;
    // } 
    // if(Controller.ButtonX.PRESSED){
    //   DoubleActingPiston.set(!DoubleActingPiston.value());
    // }
    // if(Controller.ButtonX.pressing()) {
    //   usingmlm();
    // }

    // Controller.ButtonX.pressed(clampcontrol);
    // Controller.ButtonX.released(loading);


    // ========== LOOP DELAY ========== //
    wait(20, msec);
  }
}



  

// Entry point
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  
  pre_auton();
  //Competition.test_auton();
  //Competition.test_driver();


  while (true) {
    wait(100, msec);
  }
}

