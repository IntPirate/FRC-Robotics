/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>
#include <frc/Buttons/JoystickButton.h>

class OI {
 public:
  OI();
  frc::Joystick* GetDriveStick(void);
  frc::Joystick *m_driveStick;
  frc::JoystickButton *J1_Obj_Button1, 
                      *J1_Obj_Button2, 
                      *J1_Obj_Button3,
                      *J1_Obj_Button4, 
                      *J1_Obj_Button5, 
                      *J1_Obj_Button6,
                      *J1_Obj_Button7, 
                      *J1_Obj_Button8;

private:


  
};
