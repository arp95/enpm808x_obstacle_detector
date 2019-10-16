/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        Robot.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/11/2019
 * @brief       Implementation for Robot class.
 */
#include <Robot.h>

/**
 * Robot constructor.
 */
Robot::Robot() {
}

/**
 * @brief: Sets the isImage value.
 */
void Robot::setIsImage(bool isImageValue) {
}

/**
 * @brief: Returns the isImage value.
 */
bool Robot::getIsImage() {
}

/**
 * @brief: Sets the isVideo value.
 */
void Robot::setIsVideo(bool isVideoValue) {
}

/**
 * @brief: Returns the isVideo value.
 */
bool Robot::getIsVideo() {
}

/**
 * @brief: Updates the isVideo and isImage value.
 */
void checkParser(cv::CommandLineParser parser) {
    if(parser.has("image")) {
    
    } else if(parser.has("video")) {

    }
}

/**
 * @brief: Processes the image and updates the image with bounding boxes.
 */
void Robot::processImage(std::string path) {
}

/**
 * @brief: Processes the video and updates the video frames with bounding boxes.
 */
void Robot::processVideo(std::string path) {
}
