/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        YOLOv3.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/11/2019
 * @brief       Implementation for YOLOv3 class.
 */
#include <YOLOv3.h>
#include <iterator>
#include <vector>
#include <exception>
#include<opencv2/opencv.hpp>
#include <Utils.h>
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
 *@brief: Preprocessing of the input image/video. Conversion to a
 *@brief: 4 Dimensional blob output
 */

cv::Mat YOLOv3::preprocess(const cv::Mat& frame) {
  //Get class names from coco.names
  utils.getClasses();
  cv::Mat &opBlob;
  cv::dnn::blobFromImage(frame, opBlob, 1 / 255.0,
                         cv::Size(getInputHeight(), getInputWidth()),
                         cv::Scalar(0, 0, 0),
                         true, false);
  return opBlob;
}

/**
 *@brief: Forward pass in YOLOv3 network.
 */
std::vector<cv::Mat> YOLOv3::run(const cv::Mat& frame) {
  std::vector<cv::Mat> outputs;
  cv::dnn::Net network = cv::dnn::readNetFromDarknet(
      utils.getModelConfiguration(), utils.getModelWeights());
  network.setInput(frame);
  network.forward(outputs, getOutputLayerNames(network));

  //Remove Bounding boxes that have low confidence using NMS Algorithm
  postprocess(frame, outputs);
  return outputs;
}

/**
 * Postprocessing of the output of yolov3 with nms algorithm.
 */
void YOLOv3::postprocess(const cv::Mat& frame,
                         const std::vector<cv::Mat>& outputs) {
  int outCounter = 0;
  int inCounter = 0;
  int nmsCounter = 0;
  std::vector<int> classId;
  std::vector<float> confidence;
  std::vector<cv::Rect> nmsBoxes;
  std::vector<cv::Mat>::iterator it;
  std::vector<cv::Mat>::iterator id;
  std::vector<cv::Mat>::iterator is;
  //outer loop
  for (it = 0; it < outputs.size(); ++it) {
    ++outCounter;
    //pointer to std::vector<cv::Mat> data
    float * matData = static_cast<float*>(outputs[outCounter].data);
    for (id = 0; id < outputs[outCounter].rows;
        ++id, matData = matData + outputs[outCounter].cols) {
      ++inCounter;
      cv::Mat scores = outputs[outCounter].row(inCounter).colRange(
          5, outputs[outCounter].cols);
      cv::Point detPoint;
      double confidences;
      //Find out the location of the maximum score
      cv::minMaxLoc(scores, 0, &confidences, 0, &detPoint);
      if (confidences > getConfThreshold()) {
        int centCoordinateX = static_cast<int>(matData[0] * frame.cols);
        int centCoordinateY = static_cast<int>(matData[1] * frame.rows);
        int width = static_cast<int>(matData[2] * frame.cols);
        int height = static_cast<int>(matData * frame.rows);
        int leftTop = centCoordinateX - width / 2;
        int rightBottom = centCoordinateY - height / 2;

        classId.push_back(detPoint.x);
        confidence.push_back((float) confidences);
        nmsBoxes.push_back(cv::Rect(leftTop, rightBottom, width, height));
      }
    }
  }
  std::vector<int> indices;
  cv::dnn::NMSBoxes(nmsBoxes, confidence, getConfThreshold(), getNmsThreshold(),
                    indices);
  for (is = 0; is < indices.size(); ++is) {
    ++nmsCounter;
    int id = indices[nmsCounter];
    cv::Rect box = nmsBoxes[id];
    utils.drawBoundingBox(classId[id], confidence[id], box.x, box.y,
                          box.x + box.width, box.y + box.height, frame);
}
}

/**
 *@brief: Get names/features of output layers of the network.
 */
std::vector<std::string> YOLOv3::getOutputLayerNames(const cv::dnn::Net& net) {
  int count = 0;
  std::vector<std::string> outputLayerNames;
  std::vector<std::string> oplNames;
  std::vector<std::string>::iterator it;
  net = cv::dnn::readNetFromDarknet(utils.getModelConfiguration(),
                                  utils.getModelWeights());
  outputLayerNames = net.getLayerNames();
  for (it = outputLayerNames.begin(); it < outputLayerNames.end(); it++) {
    count++;
    oplNames[count] = *it;
  }
  return oplNames;
}

virtual YOLOv3::~YOLOv3() {
std::cout << "Destructor has been called";
}
