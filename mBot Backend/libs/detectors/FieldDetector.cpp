#pragma once

#include "FieldDetector.h"
#include "../external/aruco/include/opencv2/aruco.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void FieldDetector::update(cv::Mat& image) {
    cv::Mat copy = image.clone();

    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_50);
    cv::aruco::detectMarkers(copy, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);

    cv::aruco::drawDetectedMarkers(copy, markerCorners, markerIds);

    cv::pollKey();

    cv::imshow("DEBUG FIELD DETECTOR", copy);
}


Field FieldDetector::getField() {
    return field;
}

FieldDetector::FieldDetector(){

}

FieldDetector::~FieldDetector() {

}
