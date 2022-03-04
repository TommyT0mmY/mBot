#include "ImageNormalizer.h"

void ImageNormalizer::setRawImage(cv::Mat* rawImage) {
    ImageNormalizer::rawImage_p = rawImage;
}

cv::Mat ImageNormalizer::getNormalizedImage() const {
    return ImageNormalizer::normalizedImage;
}

void ImageNormalizer::initNormalization() {

}

void ImageNormalizer::normalize() {

}
