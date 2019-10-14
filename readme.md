# Obstacle Detection using YOLO v3

[![Build Status](https://travis-ci.org/arp95/enpm808x_obstacle_detector.svg?branch=master)](https://travis-ci.org/arp95/enpm808x_obstacle_detector)
[![Coverage Status](https://coveralls.io/repos/github/arp95/enpm808x_obstacle_detector/badge.svg?branch=master)](https://coveralls.io/github/arp95/enpm808x_obstacle_detector?branch=master)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)](LICENSE.md)
---

## About the Authors

Shantam Bajpai: I am a first year graduate student pursuing my masters degree in Robotics from the University of Maryland, College Park. Prior to joining University of Maryland I completed my undergraduate in Electrical and Electronics Engineering from Vellore Institute of Technology, Vellore, India.

Arpit Aggarwal: I am a first year graduate student pursuing my masters degree in Robotics from the University of Maryland, College Park. Prior to joining University of Maryland I completed my undergraduate in Electrical Engineering from Delhi Technological University, Delhi, India.

## Overview of the project

For a robot to navigate autonomously in a given region it should have the capability to efficiently detect and avoid the obstacles that might come in its path. In this projecct we will develop a real time object detection classifier for ACME Robotics. The output obtained by the module can be used by the path planning component of the robotic system. 
The YOLOv3 object detector algorithm will be used for this on a pre-trained COCO Dataset.
	1. The module will take an nxn sized input image/video frames and will preprocess each image/frame and convert it into a blob.
	2. The output blob will then be passed as an input to the pre-trained YOLOv3 algorithm which will return a list of bounding boxes for the input image.
	3. After the output is obtained it will postprocessed and the boxes with low confidence scores will be suppressed using non max suppresion.

## Dependencies
[![OpenCV Installation](https://img.shields.io/badge/OpenCV4.0.0-Clickhere-brightgreen.svg?style=flat)](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)

## Standard install via command-line
```
git clone --recursive https://github.com/arp95/enpm808x_obstacle_detector.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/arp95/enpm808x_obstacle_detector.git

```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p enpm808x_build
cd enpm808x_build
cmake -G  "Eclipse CDT4 - Unix Makefiles" ../enpm808x_obstacle_detector/

```
## Agile Iterative Process
[![Solo Iterative Process](https://img.shields.io/badge/AIP-ClickHere-brightgreen.svg?style=flat)](https://docs.google.com/spreadsheets/d/1u8QQ8bs4w7-aTD3opihKKRTvK2XOl-JbmZHEvHiuM_Q/edit?ts=5da0a966#gid=0)
