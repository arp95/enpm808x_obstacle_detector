/**
 * Copyright 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  MockYOLOv3.cpp
 * @brief Solitary Test source file for testing the Utils
 *        class methods.Includes all the required headers
 * @author Shantam Bajpai and Arpit Aggarwal
 * @date  13th October 2019
 * @version 1.0
 *
 */

#include <gtest/gtest.h>
#include <Utils.h>

Utils Util;

/**
 * @brief Test case for getClassesFile method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesFile) {
  Util.setClassesFile("../coco.names");
  EXPECT_EQ(Util.getClassesFile(), "../coco.names");
}

/**
 * @brief Test case for getModelConfiguration method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelConfigurationFile) {
  Util.setModelConfiguration("../yolov3.cfg");
  EXPECT_EQ(Util.getModelConfiguration(), "../yolov3.cfg");
}

/**
 * @brief Test case for getModelWeights method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelWeightsFile) {
  Util.setModelWeights("../yolov3.weights");
  EXPECT_EQ(Util.getModelWeights(), "../yolov3.weights");
}

/**
 * @brief Test case for getClasses method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesSize) {
  std::vector<std::string> classes = Util.getClasses();
  EXPECT_EQ(classes.size(), 0);
}
