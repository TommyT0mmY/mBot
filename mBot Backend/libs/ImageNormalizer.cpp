#include "ImageNormalizer.h"

void ImageNormalizer::setRawImage(cv::Mat* rawImage) {
    rawImage_p = rawImage;
}

cv::Mat ImageNormalizer::getNormalizedImage() const {
    return normalizedImage;
}

void ImageNormalizer::initNormalization(cv::Point2f src[]) {
    cv::Point2f dst[4] = {
        {0.0f, 0.0f},
        {width, 0.0f},
        {0.0f, height},
        {width, height}
    };

    projectionMatrix = cv::getPerspectiveTransform(src, dst);
}

void ImageNormalizer::normalize() {
    cv::warpPerspective(
        *rawImage_p,
        normalizedImage,
        projectionMatrix,
        cv::Point(width, height)
    );
}
