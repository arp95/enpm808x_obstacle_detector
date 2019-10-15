/**
 * Copyright 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  test.cpp
 * @brief Test source file for enpm808x_obstacle_detector
 *        Contains the required headers and methods.
 * @author Shantam Bajpai and Arpit Aggarwal
 * @date  13th October 2019
 * @version 1.0
 *
 */

#include <gtest/gtest.h>
#include <Robot.h>
#include <Utils.h>
#include <YOLOv3.h>
#include <vector>

YOLOv3 yv3(1, 1, 1, 1);
Robot f;
Utils Util;
double val = 2;
int val1;

/**
 * @brief Test case for setConfThreshold method of YOLOv3 class. The
 * test checks whether value set for confidence is same as the value input
 * by the getConfThreshold method.
 */
TEST(checkGetterSetter, checkConfThreshold) {
  yv3.setConfThreshold(val);
  EXPECT_EQ(yv3.getConfThreshold(), val);
}

/**
 * @brief Test case for setNmsThreshold method of YOLOv3 class. The
 * test checks whether value set for nmsThreshold is same as the value input
 * by the getNmsThreshold method.
 */
TEST(checkGetterSetter, checknmsThreshold) {
  yv3.setNmsThreshold(val);
  EXPECT_EQ(yv3.getNmsThreshold(), val);
}

/**
 * @brief Test case for setInputWidth method of YOLOv3 class. The
 * test checks whether value set for InputWidth is same as the value input
 * by the getInputWidth method.
 */
TEST(checkGetterSetter, checkInputWidth) {
  yv3.setInputWidth(val);
  EXPECT_EQ(yv3.getInputWidth(), val1);
}

/**
 * @brief Test case for setInputHeight method of YOLOv3 class. The
 * test checks whether value set for InputHeight is same as the value input
 * by the getInputHeight method.
 */
TEST(checkGetterSetter, checkInputHeight) {
  yv3.setInputHeight(val);
  EXPECT_EQ(yv3.getInputHeight(), val1);
}

/**
 * @brief Test case for getIsImage method of Foo class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsImage) {
  f.setIsImage(0);
  EXPECT_EQ(f.getIsImage(), 0);
}

/**
 * @brief Test case for getIsVideo method of Foo class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsVideo) {
  f.setIsVideo(1);
  EXPECT_EQ(f.getIsVideo(), 1);
}

/**
 * @brief Test case for getClassesFile method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesFile) {
  Util.setClassesFile("arpit");
  EXPECT_EQ(Util.getClassesFile(), "arpit");
}

/**
 * @brief Test case for getModelConfiguration method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelConfigurationFile) {
  Util.setModelConfiguration("shantam");
  EXPECT_EQ(Util.getModelConfiguration(), "shantam");
}

/**
 * @brief Test case for getModelWeights method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelWeightsFile) {
  Util.setModelWeights("shantam");
  EXPECT_EQ(Util.getModelWeights(), "shantam");
}

/**
 * @brief Test case for getClasses method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesSize) {
  std::vector<std::string> classes = Util.getClasses();
  EXPECT_EQ(classes.size(), 0);
}
