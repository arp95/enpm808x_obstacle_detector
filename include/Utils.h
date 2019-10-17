#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

/* Copyright 2019 Arpit Aggarwal, Shantam Bajpai
 * @file Utils.h
 * @author Arpit Aggarwal, Shantam Bajpai
 */

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

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
   * @return type std::string.
   */
  std::string getClassesFile();

  /**
   * @brief  sets the classesFile value.
   * @param  one parameter, classesFile value.
   * @return type void.
   */
  void setClassesFile(const std::string classesFileValue);

  /**
   * @brief  returns the modelConfiguration value.
   * @param  no parameter.
   * @return type std::string.
   */
  std::string getModelConfiguration();

  /**
   * @brief  sets the modelConfiguration value.
   * @param  one parameter, modelConfiguration value.
   * @return type void.
   */
  void setModelConfiguration(const std::string modelConfigurationValue);

  /**
   * @brief  returns the modelWeights value.
   * @param  no parameter.
   * @return type std::string.
   */
  std::string getModelWeights();

  /**
   * @brief  sets the modelWeights value.
   * @param  one parameter, modelWeights value.
   * @return type void.
   */
  void setModelWeights(const std::string modelWeightsValue);

  /**
   * @brief  adds classes in std::vector<std::string>.
   * @param  no parameter.
   * @return type void.
   */
  void addClasses();

  /**
   * @brief  returns classes of type std::vector<std::string>.
   * @param  no parameter.
   * @return type std::vector<std::string>.
   */
  std::vector<std::string> getClasses();

  /**
   * @brief  draws bounding box given the coordinates.
   * @param  seven parameters, one is classId, confidence, left, top, right, bottom and frame image.
   * @return type void.
   */
  void drawBoundingBox(int classId, double confidence, int left, int top, int right, int bottom, const cv::Mat & frame);

  /*
   * @ brief: Destructor for class Utils
   *
   */

  virtual ~Utils();
};
#endif  // INCLUDE_UTILS_H_
