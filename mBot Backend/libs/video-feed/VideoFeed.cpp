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
    videoCapture(filename, apiPreference);
    update(); // sets to first image
}

VideoFeed::VideoFeed(int cameraId) {
    videoCapture(cameraId, apiPreference);
    update(); // sets to first image
}

VideoFeed::~VideoFeed() {

}
