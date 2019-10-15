/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        YOLOv3.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/11/2019
 * @brief       Implementation for YOLOv3 class.
 */
#include <YOLOv3.h>
#include <Utils.h>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

/**
 * YOLOv3 constructor.
 */
YOLOv3::YOLOv3() {
}

/**
 * @brief: YOLOv3 constructor with four parameters.
 */
YOLOv3::YOLOv3(double confThresholdValue, double nmsThresholdValue,
               int inputWidthValue, int inputHeightValue)
    : confThreshold(confThresholdValue),
      nmsThreshold(nmsThresholdValue),
      inputWidth(inputWidthValue),
      inputHeight(inputHeightValue) {

}

/**
 * @brief: Set confThreshold from YOLOv3 class.
 */
void YOLOv3::setConfThreshold(double confThresholdValue) {
  this->confThreshold = confThresholdValue;
}

/**
 *@brief: Get confThreshold from YOLOv3 class.
 */
double YOLOv3::getConfThreshold() {
  return this->confThreshold;
}

/**
 *@brief: Set nmsThreshold from YOLOv3 class.
 */
void YOLOv3::setNmsThreshold(double nmsThresholdValue) {
  this->nmsThreshold = nmsThresholdValue;
}

/**
 *@brief: Get nmsThreshold from YOLOv3 class.
 */
double YOLOv3::getNmsThreshold() {
  return this->nmsThreshold;
}

/**
 *@brief: Set inputWidth from YOLOv3 class.
 */
void YOLOv3::setInputWidth(int inputWidthValue) {
  this->inputWidth = inputWidthValue;
}

/**
 *@brief: Get inputWidth from YOLOv3 class.
 */
int YOLOv3::getInputWidth() {
  return this->inputWidth;
}

/**
 *@brief: Set inputHeight from YOLOv3 class.
 */
void YOLOv3::setInputHeight(int inputHeightValue) {
  this->inputHeight = inputHeightValue;
}

/**
 *@brief: Get inputHeight from YOLOv3 class.
 */
int YOLOv3::getInputHeight() {
  return this->inputHeight;
}

/**
 *@brief: Postprocessing of the output of yolov3 with nms algorithm.
 */
void YOLOv3::postprocess(cv::Mat& frame, const std::vector<cv::Mat>& outputs) {
}

/**
 *@brief: Forward pass in YOLOv3 network.
 */
std::vector<cv::Mat> YOLOv3::run(cv::Mat& frame) {
}

/**
 *@brief: Get names of output layers of the network.
 */
std::vector<std::string> YOLOv3::getOutputLayerNames(const cv::dnn::Net& net) {
}
