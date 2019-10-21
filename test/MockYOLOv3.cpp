/**
 * @copyright  MIT License (c) 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  MockYOLOv3.cpp
 * @brief Solitary Test source file for testing the YOLOv3
 *        class methods. Includes all the required headers
 * @author Shantam Bajpai and Arpit Aggarwal
 * @version 1.0
 *
 */
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>
#include "YOLOv3.h"
#include "Utils.h"

YOLOv3 yolov31;
YOLOv3 yolov32(0.5, 0.4, 416, 416);
double val = 2;

/**
 * @brief Test case for setConfThreshold method of YOLOv3 class. The
 * test checks whether value set for confidence is same as the value input
 * by the getConfThreshold method.
 */
TEST(checkGetterSetter, checkConfThreshold) {
  yolov31.setConfThreshold(val);
  EXPECT_EQ(yolov31.getConfThreshold(), val);
}

/**
 * @brief Test case for setNmsThreshold method of YOLOv3 class. The
 * test checks whether value set for nmsThreshold is same as the value input
 * by the getNmsThreshold method.
 */
TEST(checkGetterSetter, checknmsThreshold) {
  yolov31.setNmsThreshold(val);
  EXPECT_EQ(yolov31.getNmsThreshold(), val);
}

/**
 * @brief Test case for setInputWidth method of YOLOv3 class. The
 * test checks whether value set for InputWidth is same as the value input
 * by the getInputWidth method.
 */
TEST(checkGetterSetter, checkInputWidth) {
  yolov32.setInputWidth(val);
  EXPECT_EQ(yolov32.getInputWidth(), val);
}

/**
 * @brief Test case for setInputHeight method of YOLOv3 class. The
 * test checks whether value set for InputHeight is same as the value input
 * by the getInputHeight method.
 */
TEST(checkGetterSetter, checkInputHeight) {
  yolov32.setInputHeight(val);
  EXPECT_EQ(yolov32.getInputHeight(), val);
}

/**
 * @brief Test case for preprocess method. Checks for any fatal error.
 */
TEST(checkPreProcess, inputFrames) {
  cv::Mat frame = cv::imread("../sample.jpg");
  EXPECT_NO_FATAL_FAILURE({
    yolov31.preprocess(frame);
  });
}

/**
 * @brief Test case for run method. Checks for any fatal error.
 */
TEST(checkRun, inputFrames) {
  cv::Mat frame = cv::imread("../sample.jpg");
  cv::Mat blob = yolov31.preprocess(frame);
  EXPECT_NO_FATAL_FAILURE({
    std::vector<cv::Mat> outputs = yolov31.run(blob);
  });
}

/**
 * @brief Test case for postprocess method. Checks for any fatal error.
 */
TEST(checkPostProcess , inputFrames) {
  cv::Mat frame = cv::imread("../sample.jpg");
  cv::Mat blob = yolov31.preprocess(frame);
  std::vector<cv::Mat> outputs = yolov31.run(blob);
  EXPECT_NO_FATAL_FAILURE({
    yolov31.postprocess(frame, outputs);
  });
}
