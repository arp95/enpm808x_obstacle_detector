/**@copyright  MIT License (c) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        main.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @brief       main.cpp file for gtest framework.
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
