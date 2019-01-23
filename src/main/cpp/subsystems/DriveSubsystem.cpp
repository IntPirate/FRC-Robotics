/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"
#include <frc/Drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include <commands/DriveWithJoysticks.h>

DriveSubsystem::DriveSubsystem() : Subsystem("Drive") {
  //Create Motor Controllers
  //we create a Dynamic Memory, pointer "m_leftfront" points to it 
  //and then assinged it to the pointer we created (Dynamic Memory?)
  //request memory for the class ?
  m_leftfront = new frc::PWMVictorSPX(4);  //PDP15=PWM4
  m_leftback = new frc::PWMVictorSPX(3);   //PDP14=PWM3
  frc::PWMVictorSPX *m_rightfront = new frc::PWMVictorSPX(0); //PDP13=PWM0
  m_rightback = new frc::PWMVictorSPX(1);  // PDP12=PWM1

  //Create Motor Group
  m_LeftMotors = new frc::SpeedControllerGroup(*m_leftfront, *m_leftback);
  m_RightMotors = new frc::SpeedControllerGroup(*m_rightback, *m_rightfront);


  //Create Drive Controller 
//the "*m_LeftMotors" is the value that the pointer is pointing to
//because m_LeftMotors is the address of what m_LeftMotors is pointing to 
  mRobotDrive = new frc::DifferentialDrive(*m_LeftMotors, *m_RightMotors);
  mRobotTankDrive = new frc::DifferentialDrive(*m_LeftMotors, *m_RightMotors);

}

void DriveSubsystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DriveWithJoysticks());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSubsystem::DriveOnArcade(double speed, double rotation){
  mRobotDrive->ArcadeDrive(speed,rotation);
}

void DriveSubsystem::DriveOnTank(double leftspeed, double rightspeed){
  mRobotTankDrive->TankDrive(leftspeed, rightspeed);
}