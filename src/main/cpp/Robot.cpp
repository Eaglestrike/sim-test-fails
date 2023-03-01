// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DataLogManager.h>
#include <wpi/DataLog.h>

#include <frc/DataLogManager.h>
#include <wpi/DataLog.h>
#include <wpi/DataLogReader.h>



#include <iostream>

void Robot::RobotInit() {
  wpi::log::DataLog& log = frc::DataLogManager::GetLog();
  auto entry = wpi::log::StringLogEntry(log, "/simtesting/loginfo");
  entry.Append("START");
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
  wpi::log::DataLog& log = frc::DataLogManager::GetLog();
  auto entry = wpi::log::StringLogEntry(log, "/my/lucylog");
  entry.Append("LUCILLE_RENEE_KRAVERLICH");
  sleep(0.001);
  entry.Append("CALEB_IS_NOT_A_HUMAN_BEING_BUT_REALLY_NOT_KIDDING_RRR");
  auto entry2 = wpi::log::DoubleLogEntry(log, "/my/doublelog");
  entry2.Append(69.0);
  entry2.Append(100.0);
  frc::SmartDashboard::PutNumber("hey", 801.333);
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
