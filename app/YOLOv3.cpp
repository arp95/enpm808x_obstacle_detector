/**@Copyright (C) 2019 Arpit Aggarwal, Shantam Bajpai
 * @file        YOLOv3.cpp
 * @author      Arpit Aggarwal, Shantam Bajpai
 * @date        10/11/2019
 * @brief       Implementation for YOLOv3 class.
 */

#include <YOLOv3.h>
#include <iterator>

/**
 * YOLOv3 constructor.
 */
YOLOv3::YOLOv3() {
    confThreshold = 0.5;
    nmsThreshold = 0.4;
    inputWidth = 416;
    inputHeight = 416;
    utils = Utils();
    utils.addClasses();
}

/**
 * @brief: YOLOv3 constructor with four parameters.
 */
YOLOv3::YOLOv3(float confThresholdValue, float nmsThresholdValue, int inputWidthValue, int inputHeightValue) {
    confThreshold = confThresholdValue;
    nmsThreshold = nmsThresholdValue;
    inputWidth = inputWidthValue;
    inputHeight = inputHeightValue;
    utils = Utils();
    utils.addClasses();
}

/**
 * @brief: Set confThreshold from YOLOv3 class.
 */
void YOLOv3::setConfThreshold(float confThresholdValue) {
    confThreshold = confThresholdValue;
}

/**
 *@brief: Get confThreshold from YOLOv3 class.
 */
double YOLOv3::getConfThreshold() {
    return confThreshold;
}

/**
 *@brief: Set nmsThreshold from YOLOv3 class.
 */
void YOLOv3::setNmsThreshold(float nmsThresholdValue) {
    nmsThreshold = nmsThresholdValue;
}

/**
 *@brief: Get nmsThreshold from YOLOv3 class.
 */
double YOLOv3::getNmsThreshold() {
    return nmsThreshold;
}

/**
 *@brief: Set inputWidth from YOLOv3 class.
 */
void YOLOv3::setInputWidth(int inputWidthValue) {
    inputWidth = inputWidthValue;
}

/**
 *@brief: Get inputWidth from YOLOv3 class.
 */
int YOLOv3::getInputWidth() {
    return inputWidth;
}

/**
 *@brief: Set inputHeight from YOLOv3 class.
 */
void YOLOv3::setInputHeight(int inputHeightValue) {
    inputHeight = inputHeightValue;
}

/**
 *@brief: Get inputHeight from YOLOv3 class.
 */
int YOLOv3::getInputHeight() {
    return inputHeight;
}

/**
 *@brief: Preprocessing of the input image/video. Conversion to a
 *@brief: 4 Dimensional blob output
 */

cv::Mat YOLOv3::preprocess(const cv::Mat& frame) {
    cv::Mat opBlob;
    cv::dnn::blobFromImage(frame, opBlob, 1 / 255.0,
                         cv::Size(inputWidth, inputHeight),
                         cv::Scalar(0, 0, 0),
                         true, false);
    return opBlob;
}

/**
 *@brief: Forward pass in YOLOv3 network.
 */
std::vector<cv::Mat> YOLOv3::run(const cv::Mat& frame) {
    std::vector<cv::Mat> outputs;
    cv::dnn::Net network = cv::dnn::readNetFromDarknet(utils.getModelConfiguration(), utils.getModelWeights());
    // Set the blob as input to the dnn network
    network.setInput(frame);
    // Run forward pass
    network.forward(outputs, getOutputLayerNames(network));
    // Remove Bounding boxes that have low confidence using NMS Algorithm
    postprocess(frame, outputs);
    return outputs;
}

/**
 * Postprocessing of the output of yolov3 with nms algorithm.
 */
void YOLOv3::postprocess(const cv::Mat& frame, std::vector<cv::Mat>& outputs) {
    std::vector<int> classIds;
    std::vector<float> confidenceValues;
    std::vector<cv::Rect> nmsBoxes;
    std::vector<cv::Mat>::iterator it;
    std::vector<int>::iterator is;
    // Outer Loop
    for (it = outputs.begin(); it < outputs.end(); it++) {
        std::vector<int> rowNumbers;
        std::vector<int>::iterator iteratorRowNumbers;
        int row = 0;
        float* matData = reinterpret_cast<float*>((*it).data);
        rowNumbers.resize((*it).rows);

        // Inner Loop
        for (iteratorRowNumbers = rowNumbers.begin(); iteratorRowNumbers < rowNumbers.end(); iteratorRowNumbers++) {
            cv::Point detPoint;
            double confidences;
            matData = matData + (*it).cols;
            cv::Mat scores = (*it).row(row).colRange(5, (*it).cols);
           
            cv::minMaxLoc(scores, 0, &confidences, 0, &detPoint);
            if (confidences > confThreshold) {
                int centCoordinateX = static_cast<int>(matData[0] * frame.cols);
                int centCoordinateY = static_cast<int>(matData[1] * frame.rows);
                int width = static_cast<int>(matData[2] * frame.cols);
                int height = static_cast<int>(matData[3] * frame.rows);
                int leftTop = centCoordinateX - width / 2;
                int rightBottom = centCoordinateY - height / 2;

                classIds.push_back(detPoint.x);
                confidenceValues.push_back(static_cast<float>(confidences));
                nmsBoxes.push_back(cv::Rect(leftTop, rightBottom, width, height));
            }
            row = row + 1;
        }
    }

    std::vector<int> indices;
    cv::dnn::NMSBoxes(nmsBoxes, confidenceValues, confThreshold, nmsThreshold, indices);
    for (is = indices.begin(); is < indices.end(); ++is) {
        cv::Rect box = nmsBoxes[(*is)];
        utils.drawBoundingBox(classIds[(*is)], confidenceValues[(*is)], box.x, box.y, box.x + box.width, box.y + box.height, frame);
    }
}

/**
 *@brief: Get names/features of the output layers of the network.
 */
std::vector<std::string> YOLOv3::getOutputLayerNames(const cv::dnn::Net& net) {
    std::vector<std::string> outputNames;
    std::vector<std::string> outputLayerNames = net.getLayerNames();
    std::vector<int> outputLayers = net.getUnconnectedOutLayers();

    std::vector<int>::iterator iteratorOutputLayers;
    for (iteratorOutputLayers = outputLayers.begin(); iteratorOutputLayers < outputLayers.end(); iteratorOutputLayers++) {
        outputNames.push_back(outputLayerNames[(*iteratorOutputLayers) - 1]);
    }
    return outputNames;
}

YOLOv3::~YOLOv3() {
}
