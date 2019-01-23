/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>



class DriveSubsystem : public frc::Subsystem { // the ": public frc::Subsystem" is inherinting the Subsystem class 
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

// we are creating pointers 
//
  //Actuators
  frc::PWMVictorSPX *m_leftfront; //PDP15=PWM4
  frc::PWMVictorSPX *m_leftback; //PDP14=PWM3
  //frc::PWMVictorSPX *m_rightfront; //PDP13=PWM0
  frc::PWMVictorSPX *m_rightback; // PDP12=PWM1

  //Motor Groups
  frc::SpeedControllerGroup *m_LeftMotors; 
  frc::SpeedControllerGroup *m_RightMotors;
 

  //Add Drive Base
  frc::DifferentialDrive *mRobotDrive;
  frc::DifferentialDrive *mRobotTankDrive; 

 public:
  DriveSubsystem();
  void InitDefaultCommand() override;
  void DriveOnArcade(double speed, double rotation);
  void DriveOnTank(double leftspeed, double rightspeed);

};
