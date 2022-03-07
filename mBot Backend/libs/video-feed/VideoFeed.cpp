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
    this->filename = filename;
    update(); // sets to first image
}

VideoFeed::VideoFeed(int cameraId) {
    this->cameraId = cameraId;
    update(); // sets to first image
}

VideoFeed::~VideoFeed() {

}
