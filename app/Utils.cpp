/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        Utils.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/11/2019
 * @brief       Implementation for Utils class.
 */

#include <Utils.h>

/**
 * Utils constructor.
 */
Utils::Utils() {
  classesFile = "";
  modelConfiguration = "";
  modelWeights = "";
}

/**
 * Get classesFile from Utils.
 */
std::string Utils::getClassesFile() {
}

/**
 * Get modelConfiguration from Utils.
 */
std::string Utils::getModelConfiguration() {
}

/**
 * Get modelWeights from Utils.
 */
std::string Utils::getModelWeights() {
}

/**
 * Adds classes in std::vector<std::string>.
 */
void Utils::addClasses() {
}

/**
 * Returns classes of type std::vector<std::string>.
 */
std::vector<std::string> Utils::getClasses() {
}

/**
 * Draws bounding box given the coordinates.
 */
void Utils::drawBoundingBox(int classId, double confidence, int left, int top,
                            int right, int bottom, const cv::Mat& frame) {
}
