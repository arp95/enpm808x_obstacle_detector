/**
 * @copyright  MIT License (c) 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  MockYOLOv3.cpp
 * @brief Solitary Test source file for testing the Utils
 *        class methods.Includes all the required headers
 * @author Shantam Bajpai and Arpit Aggarwal
 * @version 1.0
 *
 */
#include <gtest/gtest.h>
#include "Utils.h"

Utils util;

/**
 * @brief Test case for getClassesFile method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesFile) {
  util.setClassesFile("../coco.names");
  EXPECT_EQ(util.getClassesFile(), "../coco.names");
}

/**
 * @brief Test case for getModelConfiguration method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelConfigurationFile) {
  util.setModelConfiguration("../yolov3.cfg");
  EXPECT_EQ(util.getModelConfiguration(), "../yolov3.cfg");
}

/**
 * @brief Test case for getModelWeights method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkModelWeightsFile) {
  util.setModelWeights("../yolov3.weights");
  EXPECT_EQ(util.getModelWeights(), "../yolov3.weights");
}

/**
 * @brief Test case for getClasses method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesSize) {
  util.setClassesFile("../coco.names");
  util.addClasses();
  std::vector<std::string> classes = util.getClasses();
  EXPECT_EQ(classes.size(), 80);
}

/**
 * @brief Test case for addClasses method of Utils class.
 */
TEST(checkAddClasses, checkForCorrectInput) {
  EXPECT_NO_FATAL_FAILURE({
    util.addClasses();
  });
}

/**
 * @brief Test case for drawBoundingBox method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkDrawBoundingBox) {
  util.setClassesFile("../coco.names");
  util.addClasses();
  cv::Mat frame = cv::imread("../sample.jpg", 0);
  int rows = frame.rows;
  int cols = frame.cols;
  util.drawBoundingBox(0, 99.0, 0, 0, 5, 5, frame);
  EXPECT_EQ(frame.rows, rows);
  EXPECT_EQ(frame.cols, cols);
}
