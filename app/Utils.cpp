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
    classesFile = "../coco.names";
    modelConfiguration = "../yolov3.cfg";
    modelWeights = "../yolov3.weights";
}

/**
 * Get classesFile from Utils.
 */
std::string Utils::getClassesFile() {
    return classesFile;
}

/**
 * Set classesFile from Utils.
 */
void Utils::setClassesFile(const std::string classesFileValue) {
    classesFile = classesFileValue;
}

/**
 * Get modelConfiguration from Utils.
 */
std::string Utils::getModelConfiguration() {
    return modelConfiguration;
}

/**
 * Set modelConfiguration from Utils.
 */
void Utils::setModelConfiguration(const std::string modelConfigurationValue) {
    modelConfiguration = modelConfigurationValue;
}

/**
 * Get modelWeights from Utils.
 */
std::string Utils::getModelWeights() {
    return modelWeights;
}

/**
 * Set modelWeights from Utils.
 */
void Utils::setModelWeights(const std::string modelWeightsValue) {
    modelWeights = modelWeightsValue;
}

/**
 * Adds classes in std::vector<std::string>.
 */
void Utils::addClasses() {
    std::ifstream file(classesFile.c_str());
    std::string line;
    while (std::getline(file, line)) {
        classes.push_back(line);
    }
}

/**
 * Returns classes of type std::vector<std::string>.
 */
std::vector<std::string> Utils::getClasses() {
    return classes;
}

/**
 * Draws bounding box given the coordinates.
 */
void Utils::drawBoundingBox(int classId, double confidence, int left, int top, int right, int bottom, const cv::Mat & frame) {
    // function to draw a rectangle in the image given the coordinates
    cv::rectangle(frame, cv::Point(left, top), cv::Point(right, bottom), cv::Scalar(255, 180, 60), 3);
    // get class label from classes vector
    std::string classLabel = cv::format("%.2f", confidence);
    if (classes.size() > classId) {
        classLabel = classes[classId] + ":" + classLabel;
    }
    // put information on image
    int base;
  cv::Size labelSize = cv::getTextSize(classLabel, cv::FONT_HERSHEY_DUPLEX, 0.5,
                                       1, &base);
    top = std::max(top, labelSize.height);
  cv::rectangle(frame, cv::Point(left, top - round(2.0 * labelSize.height)),
                cv::Point(left + round(2.0 * labelSize.width), top + base),
                cv::Scalar(255, 255, 255), cv::FILLED);
  cv::putText(frame, classLabel, cv::Point(left, top), cv::FONT_HERSHEY_DUPLEX,
              0.75, cv::Scalar(0, 0, 0), 1);
}

/**
 * @brief: Destructor Definition
 */

virtual Utils::~Utils() {
  std::cout << "Destructor had been invoked" << std::endl;
}
