#pragma once

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class VideoFeed {
public: enum SourceType { DISK_VIDEO, DISK_IMAGE_SEQUENCE, DISK_IMAGE, CAMERA };

private:
    const int apiPreference = cv::CAP_ANY;

    cv::Mat* image = nullptr;
    SourceType sourceType;
    std::string path = "";


public:
    void update();

    cv::Mat* getImage();

    VideoFeed();

    ~VideoFeed();
};
