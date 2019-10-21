/**
 * Copyright 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  MockYOLOv3.cpp
 * @brief Solitary Test source file for testing the Robot
 *        class methods. Includes all the required headers
 * @author Shantam Bajpai and Arpit Aggarwal
 * @date  13th October 2019
 * @version 1.0
 *
 */

#include <gtest/gtest.h>
#include <Robot.h>

Robot robo;

/**
 * @brief Test case for getIsImage method of Robot class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsImage) {
  robo.setIsImage(0);
  EXPECT_EQ(robo.getIsImage(), 0);
}

/**
 * @brief Test case for getIsVideo method of Robot class. The
 * test checks whether the boolean value for getIsImage method.
 */
TEST(checkBoolSetterGetter, checkIsVideo) {
  robo.setIsVideo(1);
  EXPECT_EQ(robo.getIsVideo(), 1);
}

/**
 * @brief Test case for processImage method of Robot class. The
 * test verifies that processImage doesnot throw an exception.
 */

TEST(checkProcessImage, noExceptionThrown) {
  EXPECT_NO_THROW( {
    robo.processImage()
    ;
  }
);
    EXPECT_NO_FATAL_FAILURE( {
    robo.processImage()
    ;
  }
);
}
/**
 * @brief Test case for processVideo method of Robot class. The
 * test verifies that processVideo doesnot throw an exception.
 */

TEST(checkProcessVideo, noExceptionThrown) {
EXPECT_NO_THROW( {
  robo.processVideo()
  ;
}
);
EXPECT_NO_FATAL_FAILURE( {
  robo.processImage()
  ;
}
);
}

