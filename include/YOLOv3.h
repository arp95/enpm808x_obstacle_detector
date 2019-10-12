#ifndef INCLUDE_YOLOv3_H_
#define INCLUDE_YOLOv3_H_

/* Copyright 2019 Arpit Aggarwal, Shantam Bajpai
 * @file YOLOv3.h
 * @author Arpit Aggarwal, Shantam Bajpai
 */

#include <iostream>
#include <Utils.h>

class YOLOv3 {
 private:
  /**
   * @brief private variable for Utils class.
   */
  Utils utils;

  /**
   * @brief private variable for confThreshold.
   */
  double confThreshold;

  /**
   * @brief private variable for nmsThreshold.
   */
  double nmsThreshold;

  /**
   * @brief private variable for inputWidth.
   */
  int inputWidth;

  /**
   * @brief private variable for storing inputHeight.
   */
  int inputHeight;

 public:
  /**
   * @brief  constructor for YOLOv3 class with no parameters.
   */
  YOLOv3();

  /**
   * @brief  constructor for YOLOv3 class with four parameters.
   */
  YOLOv3(double confThresholdValue, double nmsThresholdValue, int inputWidthValue, int inputHeightValue);

  /**
   * @brief  sets the confThreshold value.
   * @param  one parameter which is the confThreshold value.
   * @return type void.
   */
  void setConfThreshold(double confThresholdValue);

  /**
   * @brief  returns the confThreshold value.
   * @param  no parameter.
   * @return type double.
   */
  double getConfThreshold();

  /**
   * @brief  sets the nmsThreshold value.
   * @param  one parameter which is the nmsThreshold value.
   * @return type void.
   */
  void setNmsThreshold(double nmsThresholdValue);

  /**
   * @brief  returns the nmsThreshold value.
   * @param  no parameter.
   * @return type double.
   */
  double getNmsThreshold();

  /**
   * @brief  sets the inputWidth value.
   * @param  one parameter which is the inputWidth value.
   * @return type void.
   */
  void setInputWidth(int inputWidthValue);

  /**
   * @brief  returns the inputWidth value.
   * @param  no parameter.
   * @return type int.
   */
  int getInputWidth();

  /**
   * @brief  sets the inputHeight value.
   * @param  one parameter which is the inputHeight value.
   * @return type void.
   */
  void setInputHeight(int inputHeightValue);

  /**
   * @brief  returns the inputHeight value.
   * @param  no parameter.
   * @return type int.
   */
  int getInputHeight();

  /**
   * @brief  postprocessing of the output of yolov3 with nms algorithm.
   * @param  two parameters, one is frame image and the other is outputs vector.
   * @return type void.
   */
  void postprocess(cv::Mat& frame, const std::vector<cv::Mat>& outputs);

  /**
   * @brief  draws bounding box given the coordinates.
   * @param  seven parameters, one is classId, confidence, left, top, right, bottom and frame image.
   * @return type void.
   */
  void drawBoundingBox(int classId, float confidence, int left, int top, int right, int bottom, cv::Mat& frame);

  /**
   * @brief  forward pass in YOLOv3 network.
   * @param  one parameter, input frame.
   * @return type vector<cv::Mat>.
   */
  std::vector<cv::Mat> run(cv::Mat& frame);

  /**
   * @brief  get names of output layers of the network.
   * @param  one parameter, which is the cv::dnn::net.
   * @return type vector<std::string>.
   */
  std::vector<std::string> getOutputLayerNames(const cv::dnn::Net& net);
};
#endif  // INCLUDE_YOLOv3_H_
