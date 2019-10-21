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
#include "YOLOv3.h"

YOLOv3 yolov3;
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
 * @brief Test case for postProcess method. Checks for any fatal error
 */

/*TEST(checkPostProcess , inputFrames) {
  cv::VideoCapture capture;
  std::ifstream videoFile("/home/arpitdec5/Desktop/enpm808x_midterm/outputs/input_videos/run_yolov3_output.avi");
  capture.open(videoPath);
  cv::Mat frame;
  std::vector<cv::Mat> outputs;
  capture >> frame;
  std::cout << frame.rows << std::endl;
  EXPECT_NO_FATAL_FAILURE( {
    yolov3.postprocess(frame, outputs)
    ;
  });
}*/

/**
 * @brief Test case for preProcess method. Checks for any fatal error
 */

/*TEST(checkPreProcess , inputFrames) {
cv::VideoCapture video("/outputs/run_yolov3_output.avi");
  cv::Mat frame;
  video >> frame;
  EXPECT_NO_FATAL_FAILURE( {
  yv3.preprocess(frame)
    ;
  }
);
}

/**
 * @brief Test case for preProcess method. Checks for any fatal error
 */

/*TEST(checkRunMethod , inputFrames) {
cv::VideoCapture video("../outputs/run_yolov3_output.avi");
cv::Mat frame;
video >> frame;
EXPECT_NO_FATAL_FAILURE( {
yv3.run(frame)
;
}
);
 }*/
