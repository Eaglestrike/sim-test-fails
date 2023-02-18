#include <gtest/gtest.h>
#include "Robot.h"


class SimulationTest : public testing::Test {
};

TEST_F(SimulationTest, InitTest) {
    std::cout << "testing" << std::endl;
    Robot robot;
    robot.RobotInit();
}