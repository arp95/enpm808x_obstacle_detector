#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

/* @copyright  MIT License (c) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file Utils.h
 * @author Arpit Aggarwal, Shantam Bajpai
 * @brief Utils module
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @brief Utils class used in YOLOv3 class for configuring the cv::dnn::Net.
 */
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
   * @brief constructor for Utils class with no parameters.
   */
  Utils();

  /**
   * @brief returns the classesFile value.
   * @return type std::string.
   */
  std::string getClassesFile();

  /**
   * @brief sets the classesFile value.
   * @param[in] classesFileValue It is the classes filepath.
   * @return type void.
   */
  void setClassesFile(const std::string
classesFileValue);

  /**
   * @brief returns the modelConfiguration value.
   * @return type std::string.
   */
  std::string getModelConfiguration();

  /**
   * @brief sets the modelConfiguration value.
   * @param[in] modelConfigurationValue It is the file containing yolov3 configuration.
   * @return type void.
   */
  void setModelConfiguration(const std::string modelConfigurationValue);

  /**
   * @brief returns the modelWeights value.
   * @return type std::string.
   */
  std::string getModelWeights();

  /**
   * @brief sets the modelWeights value.
   * @param[in] modelWeightsValue It is the file containing yolov3 weights.
   * @return type void.
   */
  void setModelWeights(const std::string modelWeightsValue);

  /**
   * @brief adds classes in std::vector<std::string>.
   * @return type void.
   */
  void addClasses();

  /**
   * @brief returns classes of type std::vector<std::string>.
   * @return type std::vector<std::string>.
   */
  std::vector<std::string> getClasses();

  /**
   * @brief draws bounding box given the coordinates.
   * @param[in] classId It is the class id.
   * @param[in] confidence It is the confidence value.
   * @param[in] left It refers to the left coordinate.
   * @param[in] top It refers to the top coordinate.
   * @param[in] right It refers to the right coordinate.
   * @param[in] bottom It refers to the bottom coordinate
   * @param[in] frame It refers to the input image.
   * @return type void.
   */
  void drawBoundingBox(int classId, double confidence,
int left, int top, int right, int bottom, const cv::Mat & frame);

  /*
   * @brief: Destructor for class Utils
   *
   */
  virtual ~Utils();
};
#endif  // INCLUDE_UTILS_H_
