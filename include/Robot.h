#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

/* Copyright 2019 Arpit Aggarwal, Shantam Bajpai
 * @file Robot.h
 * @author Arpit Aggarwal, Shantam Bajpai
 */

#include <iostream>
#include <string>
#include <YOLOv3.h>

class Robot {
 private:
  /**
   * @brief private variable for YOLOv3 class.
   */
  YOLOv3 yolov3;

  /**
   * @brief private variable for isImage.
   */
  bool isImage;

  /**
   * @brief private variable for isVideo.
   */
  bool isVideo;

 public:
  /**
   * @brief  constructor for Robot class with no parameters.
   */
  Robot();

  /**
   * @brief  Sets the isImage value.
   * @param  one parameter, which is the isImageValue.
   * @return type bool.
   */
  void setIsImage(bool isImageValue);

  /**
   * @brief  returns the isImage value.
   * @param  no parameter.
   * @return type bool.
   */
  bool getIsImage();

  /**
   * @brief  Sets the isVideo value.
   * @param  one parameter, which is the isVideoValue.
   * @return type bool.
   */
  void setIsVideo(bool isVideoValue);

  /**
   * @brief  returns the isVideo value.
   * @param  no parameter.
   * @return type bool.
   */
  bool getIsVideo();

  /**
   * @brief  updates the isVideo and isImage value.
   * @param  no parameter.
   * @return type void.
   */
  void checkParser();

  /**
   * @brief  processes the image and updates the image with bounding boxes.
   * @param  one parameter, path of image.
   * @return type void.
   */
  void processImage(std::string path);

  /**
   * @brief  processes the video and updates the video frames with bounding boxes.
   * @param  one parameter, path of video.
   * @return type void.
   */
  void processVideo(std::string path);
};
#endif  // INCLUDE_ROBOT_H_