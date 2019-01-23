/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include <frc/WPILib.h>
#include <commands/DriveAsTank.h>
#include <commands/DriveWithJoysticks.h>

OI::OI() {
  // Process operator interface input here.

  //Create Joystick Controller Object 
  m_driveStick = new frc::Joystick(0);
  
  //Button Mapping from the joystick controller object
  //and create Button Objects 
  J1_Obj_Button1 = new frc::JoystickButton(m_driveStick,1);
  J1_Obj_Button2 = new frc::JoystickButton(m_driveStick,2);
  J1_Obj_Button3 = new frc::JoystickButton(m_driveStick,3);
  J1_Obj_Button4 = new frc::JoystickButton(m_driveStick,4);
  J1_Obj_Button5 = new frc::JoystickButton(m_driveStick,5);
  J1_Obj_Button6 = new frc::JoystickButton(m_driveStick,6);
  J1_Obj_Button7 = new frc::JoystickButton(m_driveStick,7);
  J1_Obj_Button8 = new frc::JoystickButton(m_driveStick,8);


  J1_Obj_Button1->WhenPressed(new DriveAsTank());
  J1_Obj_Button2->WhenActive(new DriveWithJoysticks());

  //m_Button1->WhenPressed(new ToggleOriantation());

}


frc::Joystick* OI::GetDriveStick(void){
  return m_driveStick;
}