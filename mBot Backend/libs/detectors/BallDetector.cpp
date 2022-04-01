#include "BallDetector.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <vector>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/opencv.hpp>

// "opencv2\features2d.hpp"

BallDetector::BallDetector() {
	auto params = cv::SimpleBlobDetector::Params();

	params.filterByArea = true;
	params.filterByColor = true;

	params.minArea = 300;
	params.maxArea = 4000;
	params.blobColor = 255;

	detector = cv::SimpleBlobDetector::create(params);
	/*
	cv::namedWindow("Trackbar");

	cv::createTrackbar("Low H", "Trackbar", &lowH, 180);
	cv::createTrackbar("High H", "Trackbar", &highH, 180);
	cv::createTrackbar("Low S", "Trackbar", &lowS, 255);
	cv::createTrackbar("High S", "Trackbar", &highS, 255);
	cv::createTrackbar("Low V", "Trackbar", &lowV, 255);
	cv::createTrackbar("High V", "Trackbar", &highV, 255);
	*/
}

void BallDetector::update(cv::Mat& image) {
	cv::Mat HSVImage;
	cv::cvtColor(image, HSVImage, cv::COLOR_BGR2HSV);

	cv::Mat thresholdImage;
	cv::inRange(HSVImage, cv::Scalar(lowH, lowS, lowV), cv::Scalar(highH, highS, highV), thresholdImage);

	cv::imshow("threshold", thresholdImage);
	
	std::vector<cv::KeyPoint> keyPoints;
	detector->detect(thresholdImage, keyPoints);

	cv::Mat imageK;
	cv::drawKeypoints(image, keyPoints, imageK, cv::Scalar(0, 0, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	cv::circle(imageK, { 250, 250 }, 20, cv::Scalar(255, 0, 0));
	cv::circle(imageK, { 250, 250 }, 35, cv::Scalar(255, 0, 0));


	cv:imshow("KeyPointsImage", imageK);
	cv::pollKey();
}

Ball BallDetector::getBall() {
	return ball;
}
