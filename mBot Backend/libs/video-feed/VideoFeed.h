#pragma once

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class VideoFeed {
//public:
//    enum class SourceType { DISK_VIDEO, DISK_IMAGE_SEQUENCE, DISK_IMAGE, CAMERA };
//
private:
    const int apiPreference = cv::CAP_ANY;

    cv::VideoCapture videoCapture;
    cv::Mat* image = nullptr;
    
    std::string filename = "";
    int cameraId = 0;

    void update();
public:
    cv::Mat* getImage();

    cv::Mat* nextImage();

    VideoFeed(std::string filename);
    VideoFeed(int cameraId);

    ~VideoFeed();
};
