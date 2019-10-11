#ifndef INCLUDE_Utils_H_
#define INCLUDE_Utils_H_

/* Copyright 2019 Arpit Aggarwal, Shantam Bajpai
 * @file Utils.h
 * @author Arpit Aggarwal, Shantam Bajpai
 */

#include <iostream>
#include <string>

class Utils {
 private:
  /**
   * @brief private variable for classesFile.
   */
  string classesFile;

  /**
   * @brief private variable for modelConfiguration.
   */
  string modelConfiguration;

  /**
   * @brief private variable for modelWeights.
   */
  string modelWeights;

 public:
  /**
   * @brief  constructor for Utils class with no parameters.
   */
  Utils();

  /**
   * @brief  returns the classesFile value.
   * @param  no parameter.
   * @return type string.
   */
  string getClassesFile();

  /**
   * @brief  returns the modelConfiguration value.
   * @param  no parameter.
   * @return type string.
   */
  string getModelConfiguration();

  /**
   * @brief  returns the modelWeights value.
   * @param  no parameter.
   * @return type string.
   */
  string getModelWeights();
};
