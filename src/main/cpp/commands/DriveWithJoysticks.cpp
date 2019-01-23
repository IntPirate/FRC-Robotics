/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveWithJoysticks.h"
#include "Robot.h"
#include <frc/Joystick.h>
#include <frc/GenericHID.h>

DriveWithJoysticks::DriveWithJoysticks(){
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::driveSS);
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {
    m_driveStick = Robot::m_oi.GetDriveStick();
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
  
  Robot::driveSS.DriveOnArcade(m_driveStick->GetY(), m_driveStick->GetX());

}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithJoysticks::End() {
  
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {
  End();
}
