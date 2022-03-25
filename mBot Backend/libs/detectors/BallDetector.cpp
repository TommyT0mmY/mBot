#include "BallDetector.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <vector>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/opencv.hpp>

// "opencv2\features2d.hpp"

BallDetector::BallDetector() {
	auto params = cv::SimpleBlobDetector::Params();

	detector = cv::SimpleBlobDetector::create(params);
}

void BallDetector::update(cv::Mat& image) {
	cv::Mat HSVImage;
	cv::cvtColor(image, HSVImage, cv::COLOR_BGR2HSV);

	cv::Mat thresholdImage;
	cv::inRange(HSVImage, cv::Scalar(lowH, lowS, lowV), cv::Scalar(highH, highS, highV), thresholdImage);



	std::vector<cv::KeyPoint> keyPoints;
	detector->detect(thresholdImage, keyPoints);

	cv::Mat imageK;
	cv::drawKeypoints(image, keyPoints, imageK, cv::Scalar(0, 0, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	cv:imshow("KeyPointsImage", imageK);
	cv::pollKey();
}


void BallDetector::searchBall() {

}

Ball BallDetector::getBall() {
	return ball;
}
