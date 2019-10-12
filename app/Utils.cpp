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
string Utils::getClassesFile() {
  return classesFile;
}

/**
 * Get modelConfiguration from Utils.
 */
string Utils::getModelConfiguration() {
  return modelConfiguration;
}

/**
 * Get modelWeights from Utils.
 */
string Utils::getModelWeights() {
  return modelWeights;
}
