/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        main.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/12/2019
 * @brief       Implementation for main(Robot) class.
 */

/*Include headers.....................*/

const char* keys =
"{help h usage ? | | Usage examples: \n\t\t./object_detection_yolo.out --image=dog.jpg \n\t\t./object_detection_yolo.out --video=run_sm.mp4}"
"{image i        |<none>| input image   }"
"{video v       |<none>| input video   }"
;

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <Robot.h>

int main(int argc, char** argv) {
    cv::CommandLineParser parser(argc, argv, keys);
    Robot robot;
    robot.checkParser(parser);
    return 0;
}

