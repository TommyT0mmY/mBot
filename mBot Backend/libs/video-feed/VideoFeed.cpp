#include "VideoFeed.h"

void VideoFeed::update() {
    videoCapture.grab();
    bool result = videoCapture.retrieve(*image);
    if (!result) image = nullptr;
}

cv::Mat* VideoFeed::getImage() {
    return image;
}

cv::Mat* VideoFeed::nextImage() {
    update();
    return getImage();
}

VideoFeed::VideoFeed(std::string filename) {
    image = new cv::Mat;
    videoCapture = cv::VideoCapture(filename, apiPreference);
    update(); // sets to first image
}

VideoFeed::VideoFeed(int cameraId) {
    image = new cv::Mat;
    videoCapture = cv::VideoCapture(cameraId, apiPreference);
    update(); // sets to first image
}

VideoFeed::~VideoFeed() {
    delete image;
}
