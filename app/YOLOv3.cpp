/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        YOLOv3.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/11/2019
 * @brief       Implementation for YOLOv3 class.
 */
#include <YOLOv3.h>

/**
 * YOLOv3 constructor.
 */
YOLOv3::YOLOv3() {
}

/**
 * YOLOv3 constructor with four parameters.
 */
YOLOv3::YOLOv3(double confThresholdValue, double nmsThresholdValue, int inputWidthValue, int inputHeightValue) {
}

/**
 * Set confThreshold from YOLOv3 class.
 */
void YOLOv3::setConfThreshold(double confThresholdValue) {
}

/**
 * Get confThreshold from YOLOv3 class.
 */
double YOLOv3::getConfThreshold() {
}

/**
 * Set nmsThreshold from YOLOv3 class.
 */
void YOLOv3::setNmsThreshold(double nmsThresholdValue) {
}

/**
 * Get nmsThreshold from YOLOv3 class.
 */
double YOLOv3::getNmsThreshold() {
}

/**
 * Set inputWidth from YOLOv3 class.
 */
void YOLOv3::setInputWidth(int inputWidthValue) {
}

/**
 * Get inputWidth from YOLOv3 class.
 */
int YOLOv3::getInputWidth() {
}

/**
 * Set inputHeight from YOLOv3 class.
 */
void YOLOv3::setInputHeight(int inputHeightValue) {
}

/**
 * Get inputHeight from YOLOv3 class.
 */
int YOLOv3::getInputHeight() {
}

/**
 * Preprocessing of input image.
 */
cv::Mat YOLOv3::preprocessImage(cv::Mat& frame) {
}

/**
 * Forward pass in YOLOv3 network.
 */
std::vector<cv::Mat> YOLOv3::run(cv::Mat& frame) {
}

/**
 * Postprocessing of the output of yolov3 with nms algorithm.
 */
void YOLOv3::postprocess(cv::Mat& frame, const std::vector<cv::Mat>& outputs) {
}

/**
 * Get names of output layers of the network.
 */
std::vector<std::string> YOLOv3::getOutputLayerNames(const cv::dnn::Net& net) {
}
