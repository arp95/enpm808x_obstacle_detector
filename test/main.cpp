/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        main.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/14/2019
 * @brief       main.cpp file for gtest framework.
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
