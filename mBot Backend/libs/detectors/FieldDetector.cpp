#pragma once

#include "FieldDetector.h"
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>

void FieldDetector::update(cv::Mat& image) {
    bool detectResult = qrCodeDetector.detectAndDecodeMulti(image, updateDecodeInfo, updateCorners);
    CV_UNUSED(detectResult);

    cv::Mat copy = image.clone();
    cv::Scalar color(255, 0, 0);
    cv::circle(copy, cv::Point2f(10.f, 10.f), 100, color, cv::FILLED);

    cv::pollKey();
    
    for (cv::Point currPoint : updateCorners) {
        cv::circle(copy, currPoint, 20, color, cv::FILLED);
    }

    for (int i = 0; i < updateDecodeInfo.size(); ++i) {
        std::string currCode = updateDecodeInfo[i];
        /*
        if (currCode == "TOP_LEFT")
            
        if (currCode == "TOP_RIGHT")

        if (currCode == "BOTTOM_LEFT")

        if (currCode == "BOTTOM_RIGHT")
*/
    }

    cv::imshow("DEBUG FIELD DETECTOR", copy);
}


Field FieldDetector::getField() {
    return field;
}

FieldDetector::FieldDetector(){

}

FieldDetector::~FieldDetector() {

}
