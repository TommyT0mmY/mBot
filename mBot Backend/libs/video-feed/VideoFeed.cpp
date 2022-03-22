#include "VideoFeed.h"

#include <iostream>

void VideoFeed::update() {
    //bool result = videoCapture.retrieve(*image);
    bool result = videoCapture.read(image);
    if (!result) image.empty();
}

cv::Mat* VideoFeed::getImage() {
    return &image;
}

cv::Mat* VideoFeed::nextImage() {
    update();
    return getImage();
}

VideoFeed::VideoFeed(std::string filename) {
    image.empty();

    std::cout << image << std::endl;
    videoCapture = cv::VideoCapture(filename, apiPreference);
    update(); // sets to first image
}

VideoFeed::VideoFeed(int cameraId) {
    image.empty();
    std::cout << image << std::endl;
    videoCapture = cv::VideoCapture(cameraId, apiPreference);
    update(); // sets to first image
}

VideoFeed::~VideoFeed() {
    //delete image;
}
