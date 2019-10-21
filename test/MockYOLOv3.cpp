/**
 * Copyright 2019 Shantam Bajpai and Arpit Aggarwal
 * @file  MockYOLOv3.cpp
 * @brief Solitary Test source file for testing the YOLOv3
 *        class methods. Includes all the required headers
 * @author Shantam Bajpai and Arpit Aggarwal
 * @date  13th October 2019
 * @version 1.0
 *
 */

#include <gtest/gtest.h>
#include <YOLOv3.h>

YOLOv3 yv3;

double val = 2;

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
  EXPECT_EQ(yv3.getInputWidth(), val);
}

/**
 * @brief Test case for setInputHeight method of YOLOv3 class. The
 * test checks whether value set for InputHeight is same as the value input
 * by the getInputHeight method.
 */
TEST(checkGetterSetter, checkInputHeight) {
  yv3.setInputHeight(val);
  EXPECT_EQ(yv3.getInputHeight(), val);
}

/**
 * @brief Test case for getOutputLayerNames method. Checks whether
 * output layer names have been obtained or not
 */
