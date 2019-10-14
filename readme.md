# Obstacle Detection using YOLO v3
[![Build Status](https://travis-ci.org/arp95/enpm808x_obstacle_detector.svg?branch=master)](https://travis-ci.org/arp95/enpm808x_obstacle_detector)
[![Coverage Status](https://coveralls.io/repos/github/arp95/enpm808x_obstacle_detector/badge.svg?branch=master)](https://coveralls.io/github/arp95/enpm808x_obstacle_detector?branch=master)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)](LICENSE.md)
---

## Overview of the project

For a robot to navigate autonomously in a given region it should have the capability to efficiently detect and avoid the obstacles that might come in its path. In this projecct we have developed a real time object detection classifier for ACME Robotics. The output obtained by the module can be used by the path planning component of the robotic system. 
The YOLOv3 object detector algorithm has been used for this on a pre-trained COCO Dataset.

## Dependencies

[![OpenCV Installation](https://img.shields.io/badge/OpenCV-Clickhere-brightgreen.svg?style=flat)](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)

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
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p enpm808x_build
cd enpm808x_build
cmake -G  "Eclipse CDT4 - Unix Makefiles" ../enpm808x_obstacle_detector/

```
