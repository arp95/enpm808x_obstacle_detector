/**@copyright  MIT License (c) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        Robot.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @brief       Implementation for Robot class.
 */
#include "Robot.h"
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>

/**
 * Robot constructor.
 */
Robot::Robot() {
    yolov3 = YOLOv3();
    isImage = 0;
    isVideo = 0;
    imagePath = std::string("");
    videoPath = std::string("");
}

/**
 * @brief: Sets the isImage value.
 */
void Robot::setIsImage(bool isImageValue) {
  isImage = isImageValue;
}

/**
 * @brief: Returns the isImage value.
 */
bool Robot::getIsImage() {
    return isImage;
}

/**
 * @brief: Sets the isVideo value.
 */
void Robot::setIsVideo(bool isVideoValue) {
    isVideo = isVideoValue;
}

/**
 * @brief: Returns the isVideo value.
 */
bool Robot::getIsVideo() {
    return isVideo;
}

/**
 * @brief: Updates the isVideo and isImage value and sets the imagePath and videoPath.
 */
void Robot::checkParser(cv::CommandLineParser parser) {
    if (parser.has("image")) {
        isImage = 1;
        imagePath = parser.get<std::string>("image");
    } else if (parser.has("video")) {
        isVideo = 1;
        videoPath = parser.get<std::string>("video");
    }
}

/**
 * @brief: Processes the image and updates the image with bounding boxes.
 */
void Robot::processImage() {
    try {
        std::ifstream imageFile(imagePath);
        if (!imageFile) {
            throw("Image file required!");
        }

        // read image
        cv::Mat frame, blob;
        cv::VideoCapture capture;
        std::string outputFile;
        capture.open(imagePath);
        imagePath.replace(imagePath.end() - 4, imagePath.end(), "_yolov3_output.jpg");
        outputFile = imagePath;

        // perform analysis
        capture >> frame;
        blob = yolov3.preprocess(frame);
        std::vector<cv::Mat> outputs = yolov3.run(blob);
        yolov3.postprocess(frame, outputs);

        // write frame
        cv::Mat finalFrame;
        frame.convertTo(finalFrame, CV_8U);
        cv::imwrite(outputFile, finalFrame);
        capture.release();
    } catch(...) {
        std::cout << "Image File required!" << std::endl;
    }
}

/**
 * @brief: Processes the video and updates the video frames with bounding boxes.
 */
void Robot::processVideo() {
    try {
        std::ifstream videoFile(videoPath);
        if (!videoFile) {
            throw("Video file required!");
        }

        // read video
        cv::Mat frame, blob;
        cv::VideoCapture capture;
        cv::VideoWriter outputVideo;
        std::string outputFile;
        capture.open(videoPath);
        videoPath.replace(videoPath.end() - 4, videoPath.end(), "_yolov3_output.avi");
        outputFile = videoPath;
        outputVideo.open(outputFile, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 28, cv::Size(capture.get(cv::CAP_PROP_FRAME_WIDTH), capture.get(cv::CAP_PROP_FRAME_HEIGHT)));
        while (1) {
            // perform analysis
            capture >> frame;
            if (frame.empty()) {
                break;
            }
            blob = yolov3.preprocess(frame);
            std::vector<cv::Mat> outputs = yolov3.run(blob);
            yolov3.postprocess(frame, outputs);

            // write frame to video
            cv::Mat finalFrame;
            frame.convertTo(finalFrame, CV_8U);
            outputVideo.write(finalFrame);
        }
        capture.release();
        outputVideo.release();
    } catch(...) {
        std::cout << "Video File required!" << std::endl;
    }
}
