#ifndef INCLUDE_YOLOV3_H_
#define INCLUDE_YOLOV3_H_

/* @copyright  MIT License (c) 2019 Shantam Bajpai, Arpit Aggarwal
 * @file YOLOv3.h
 * @author Shantam Bajpai, Arpit Aggarwal
 * @brief YOLOv3 module
 */
#pragma once
#include <Utils.h>
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>

/**
 * @brief YOLOv3 class responsible for running object detection on image or video.
 */
class YOLOv3 {
 private:
  /**
   * @brief private variable for Utils class.
   */
  Utils utils;

  /**
   * @brief private variable for confThreshold.
   */
  float confThreshold;

  /**
   * @brief private variable for nmsThreshold.
   */
  float nmsThreshold;

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
  YOLOv3(float confThresholdValue, float nmsThresholdValue, int inputWidthValue, int inputHeightValue);

  /**
   * @brief  sets the confThreshold value.
   * @param  one parameter which is the confThreshold value.
   * @return type void.
   */
  void setConfThreshold(float confThresholdValue);

  /**
   * @brief  returns the confThreshold value.
   * @param  no parameter.
   * @return type float.
   */
  float getConfThreshold();

  /**
   * @brief  sets the nmsThreshold value.
   * @param  one parameter which is the nmsThreshold value.
   * @return type void.
   */
  void setNmsThreshold(float nmsThresholdValue);

  /**
   * @brief  returns the nmsThreshold value.
   * @param  no parameter.
   * @return type float.
   */
  float getNmsThreshold();

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
   * @brief  preprocessing of the input image.
   * @param  one parameter, which is the input image.
   * @return type cv::Mat.
   */
  cv::Mat preprocess(const cv::Mat& frame);

  /**
   * @brief  forward pass in YOLOv3 network.
   * @param  one parameter, input frame.
   * @return type vector<cv::Mat>.
   */
  std::vector<cv::Mat> run(const cv::Mat& frame);

  /**
   * @brief  postprocessing of the output of yolov3 with nms algorithm.
   * @param  two parameters, one is frame image and the other is outputs vector.
   * @return type void.
   */
  void postprocess(const cv::Mat& frame, std::vector<cv::Mat>& outputs);

  /**
   * @brief  get names of output layers of the network.
   * @param  one parameter, which is the cv::dnn::net.
   * @return type std::vector<std::string>.
   */
  std::vector<std::string> getOutputLayerNames(const cv::dnn::Net& net);

  /*
   * @brief: Destructor for YOLOv3
   */
  virtual ~YOLOv3();
};
#endif  // INCLUDE_YOLOV3_H_
