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
   * @brief private variable for classes.
   */
  std::vector<std::string> classes;

  /**
   * @brief private variable for classesFile.
   */
  std::string classesFile;

  /**
   * @brief private variable for modelConfiguration.
   */
  std::string modelConfiguration;

  /**
   * @brief private variable for modelWeights.
   */
  std::string modelWeights;

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
  std::string getClassesFile();

  /**
   * @brief  returns the modelConfiguration value.
   * @param  no parameter.
   * @return type string.
   */
  std::string getModelConfiguration();

  /**
   * @brief  returns the modelWeights value.
   * @param  no parameter.
   * @return type string.
   */
  std::string getModelWeights();

  /**
   * @brief  adds classes in vector<string>.
   * @param  no parameter.
   * @return type void.
   */
  void addClasses();

  /**
   * @brief  returns classes of type vector<string>.
   * @param  no parameter.
   * @return type std::vector<std::string>.
   */
  std::vector<std::string> getClasses();

  /**
   * @brief  draws bounding box given the coordinates.
   * @param  seven parameters, one is classId, confidence, left, top, right, bottom and frame image.
   * @return type void.
   */
  void drawBoundingBox(int classId, float confidence, int left, int top, int right, int bottom, cv::Mat& frame);
};
#endif  // INCLUDE_Utils_H_
