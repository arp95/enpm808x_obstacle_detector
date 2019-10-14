#ifndef INCLUDE_FOO_H_
#define INCLUDE_FOO_H_

/* Copyright 2019 Arpit Aggarwal, Shantam Bajpai
 * @file Foo.h
 * @author Arpit Aggarwal, Shantam Bajpai
 */

#include <iostream>
#include <string>
#include <YOLOv3.h>

class Foo {
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
   * @brief  constructor for Foo class with no parameters.
   */
  Foo();
  /**
   * @brief  Sets the isImage value.
   * @param  no parameter.
   * @return type bool.
   */

  void setIsImage(bool isImage);

  /**
   * @brief  returns the isImage value.
   * @param  no parameter.
   * @return type bool.
   */
  bool getIsImage();

  /**
   * @brief  Sets the isVideo value.
   * @param  no parameter.
   * @return type bool.
   */

  void setIsVideo(bool isVideo);

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
#endif  // INCLUDE_FOO_H_
