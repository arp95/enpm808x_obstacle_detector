/**@copyright  MIT License (c) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        main.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @brief       Implementation for main(Robot) class.
 */
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include "Robot.h"

// keys It is used for showing parsing examples.
const char* keys =
"{help h usage ? | | Usage examples: \n\t\t./object_detection_yolo.out --image=dog.jpg \n\t\t./object_detection_yolo.out --video=run_sm.mp4}"
"{image i        |<none>| input image   }"
"{video v       |<none>| input video   }";

int main(int argc, char** argv) {
    // run main code
    cv::CommandLineParser parser(argc, argv, keys);
    Robot robot;
    robot.checkParser(parser);
    if (robot.getIsImage()) {
        robot.processImage();
    } else {
        robot.processVideo();
    }
    return 0;
}
