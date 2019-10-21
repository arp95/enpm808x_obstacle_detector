/**
 * @copyright  MIT License (c) 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  MockYOLOv3.cpp
 * @brief Solitary Test source file for testing the Robot
 *        class methods. Includes all the required headers
 * @author Shantam Bajpai and Arpit Aggarwal
 * @version 1.0
 *
 */

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "Robot.h"

// keys It is used for showing parsing examples.
const char* keys =
"{help h usage ? | | Usage examples: \n\t\t./object_detection_yolo.out --image=dog.jpg \n\t\t./object_detection_yolo.out --video=run_sm.mp4}"
"{image i        |<none>| input image   }"
"{video v       |<none>| input video   }";
Robot robot;

/**
 * @brief Test case for getIsImage method of Robot class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsImage) {
  robot.setIsImage(0);
  EXPECT_EQ(robot.getIsImage(), 0);
}

/**
 * @brief Test case for getIsVideo method of Robot class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsVideo) {
  robot.setIsVideo(1);
  EXPECT_EQ(robot.getIsVideo(), 1);
}

/**
 * @brief Test case for checkParser method of Robot class.
 */
TEST(checkBoolSetterGetter, checkParser) {
  int argc = 0;
  const char *argv = "";
  cv::CommandLineParser parser(argc, &argv, keys);
  EXPECT_EQ(robot.checkParser(parser), -1);
}

/**
 * @brief Test case for processImage method of Robot class. The
 * test verifies that processImage doesnt throw an exception.
 */

TEST(checkProcessImage, noExceptionThrown) {
  EXPECT_NO_THROW( {
    robot.processImage()
    ;
  });
    EXPECT_NO_FATAL_FAILURE( {
    robot.processImage()
    ;
  });
}

/**
 * @brief Test case for processVideo method of Robot class. The
 * test verifies that processVideo doesnt throw an exception.
 */
TEST(checkProcessVideo, noExceptionThrown) {
  EXPECT_NO_THROW( {
    robot.processVideo()
    ;
  });
  EXPECT_NO_FATAL_FAILURE( {
    robot.processVideo()
    ;
  });
}
