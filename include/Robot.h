#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

/* @copyright  MIT License (c) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file Robot.h
 * @author Arpit Aggarwal, Shantam Bajpai
 * @brief Robot module
 */
#pragma once
#include <iostream>
#include <string>
#include <YOLOv3.h>

/**
 * @brief Robot class responsible for running yolov3 on image or video.
 */
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

  /**
   * @brief private variable for imagePath.
   */
  std::string imagePath;

   /**
   * @brief private variable for videoPath.
   */
  std::string videoPath;

 public:
  /**
   * @brief constructor for Robot class with no parameters.
   */
  Robot();

  /**
   * @brief Sets the isImage value.
   * @param[in] isImageValue It is a variable that tells whether it is an image or not.
   * @return type void.
   */
  void setIsImage(bool isImageValue);

  /**
   * @brief returns the isImage value.
   * @return type bool.
   */
  bool getIsImage();

  /**
   * @brief Sets the isVideo value.
   * @param[in] isVideoValue It is a variable that tells whether it is an video or not.
   * @return type void.
   */
  void setIsVideo(bool isVideoValue);

  /**
   * @brief  returns the isVideo value.
   * @return type bool.
   */
  bool getIsVideo();

  /**
   * @brief  returns the videoPath value.
   * @return type std::string.
   */
  std::string getVideoPath();

  /**
   * @brief Sets the videoPath value.
   * @param[in] videoPathValue It is a variable that sets videoPath value.
   * @return type void.
   */
  void setVideoPath(std::string videoPathValue);

  /**
   * @brief  returns the imagePath value.
   * @return type std::string.
   */
  std::string getImagePath();

  /**
   * @brief Sets the imagePath value.
   * @param[in] imagePathValue It is a variable that sets imagePath value.
   * @return type void.
   */
  void setImagePath(std::string imagePathValue);

  /**
   * @brief updates isVideo and isImage values.
   * @param[in] parser It containes information about the imagepath and videopath.
   * @return type int.
   */
  int checkParser(cv::CommandLineParser parser);

  /**
   * @brief processes the image and updates the image with bounding boxes.
   * @return type void.
   */
  void processImage();

  /**
   * @brief processes the video and updates the video frames with bounding boxes.
   * @return type void.
   */
  void processVideo();
};
#endif  // INCLUDE_ROBOT_H_
