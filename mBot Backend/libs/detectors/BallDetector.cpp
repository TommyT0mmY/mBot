#include "BallDetector.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

void BallDetector::update(cv::Mat& image) {
	cv::Mat HSVimage;
	cv::Mat thresholdImage;
	
	cv::cvtColor(image, HSVimage, cv::COLOR_BGR2HSV);

	cv::inRange(
		HSVimage, 
		cv::Scalar(lowH, lowS, lowV), 
		cv::Scalar(highH, highS, highV), 
		thresholdImage
	);

	
}

void BallDetector::searchBall() {

}

Ball BallDetector::getBall() {
	return ball;
}
