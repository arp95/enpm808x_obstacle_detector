/**
 * @copyright  MIT License (c) 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  test.cpp
 * @brief Test source file for enpm808x_obstacle_detector
 *        Contains the required headers and methods.
 * @author Shantam Bajpai and Arpit Aggarwal
 * @version 1.0
 *
 */

#include <gtest/gtest.h>
#include "Robot.h"
#include "Utils.h"
#include "YOLOv3.h"
#include <vector>
#include <string>

YOLOv3 yolov3(1, 1, 1, 1);
Robot robot;
Utils util;
double val = 2;

/**
 * @brief Test case for setConfThreshold method of YOLOv3 class. The
 * test checks whether value set for confidence is same as the value input
 * by the getConfThreshold method.
 */
TEST(checkGetterSetter, checkConfThreshold) {
  yolov3.setConfThreshold(val);
  EXPECT_EQ(yolov3.getConfThreshold(), val);
}

/**
 * @brief Test case for setNmsThreshold method of YOLOv3 class. The
 * test checks whether value set for nmsThreshold is same as the value input
 * by the getNmsThreshold method.
 */
TEST(checkGetterSetter, checknmsThreshold) {
  yolov3.setNmsThreshold(val);
  EXPECT_EQ(yolov3.getNmsThreshold(), val);
}

/**
 * @brief Test case for setInputWidth method of YOLOv3 class. The
 * test checks whether value set for InputWidth is same as the value input
 * by the getInputWidth method.
 */
TEST(checkGetterSetter, checkInputWidth) {
  yolov3.setInputWidth(val);
  EXPECT_EQ(yolov3.getInputWidth(), val);
}

/**
 * @brief Test case for setInputHeight method of YOLOv3 class. The
 * test checks whether value set for InputHeight is same as the value input
 * by the getInputHeight method.
 */
TEST(checkGetterSetter, checkInputHeight) {
  yolov3.setInputHeight(val);
  EXPECT_EQ(yolov3.getInputHeight(), val);
}

/**
 * @brief Test case for getIsImage method of Foo class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsImage) {
  robot.setIsImage(0);
  EXPECT_EQ(robot.getIsImage(), 0);
}

/**
 * @brief Test case for getIsVideo method of Foo class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsVideo) {
  robot.setIsVideo(1);
  EXPECT_EQ(robot.getIsVideo(), 1);
}

/**
 * @brief Test case for getClassesFile method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesFile) {
  util.setClassesFile("arpit");
  EXPECT_EQ(util.getClassesFile(), "arpit");
}

/**
 * @brief Test case for getModelConfiguration method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelConfigurationFile) {
  util.setModelConfiguration("shantam");
  EXPECT_EQ(util.getModelConfiguration(), "shantam");
}

/**
 * @brief Test case for getModelWeights method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelWeightsFile) {
  util.setModelWeights("shantam");
  EXPECT_EQ(util.getModelWeights(), "shantam");
}

/**
 * @brief Test case for getClasses method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesSize) {
  util.addClasses();
  std::vector<std::string> classes = util.getClasses();
  EXPECT_EQ(classes.size(), 0);
}
