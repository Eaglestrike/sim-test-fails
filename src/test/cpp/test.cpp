#include <gtest/gtest.h>
#include "Robot.h"

#include <frc/DataLogManager.h>
#include <wpi/DataLog.h>
#include <wpi/DataLogReader.h>

#include "fmt/chrono.h"
#include "fmt/format.h"
#include "wpi/DataLogReader.h"
#include "wpi/DenseMap.h"
#include "wpi/MemoryBuffer.h"

#include <frc/simulation/DriverStationSim.h>
#include <frc/simulation/JoystickSim.h>
#include <frc/simulation/PWMSim.h>
#include <frc/simulation/SimHooks.h>
#include <hal/simulation/MockHooks.h>

#include <iostream>
#include <fstream>
#include "SimTesting.h"

//#include "mytestinc.h"


class SimulationTest : public testing::Test {
    Robot m_robot;
    std::optional<std::thread> m_thread;

public:
  void SetUp() override {
    frc::sim::PauseTiming();

    m_thread = std::thread([&] { m_robot.StartCompetition(); });
    frc::sim::StepTiming(0.0_ms);  // Wait for Notifiers
  }

  void TearDown() override {
    m_robot.EndCompetition();
    m_thread->join();

    frc::sim::DriverStationSim::ResetData();
  }
};

TEST_F(SimulationTest, InitTest) {
    SimTesting simTest;
    std::string ret = simTest.runTest("../../../../../expected-log.csv", "test-log-new", "debug-log-new", 0.2_s, SimTesting::TestMode::AUTONOMOUS);
    if (ret != "") {
        FAIL() << ret;
    }
}