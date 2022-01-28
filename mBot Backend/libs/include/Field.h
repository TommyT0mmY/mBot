#pragma once

#include "Detector.h"
#include <opencv2/core/core.hpp>

/// <summary>
/// Handles the game field
/// </summary>
class Field {
protected:
	/// <summary>
	/// Normalized image of the field
	/// Normalized using <see cref="projectionMatrix"/>
	/// </summary>
	cv::Mat fieldImage;

private:
	/// <summary>
	/// Four <see cref="cv::Point"/>
	/// </summary>
	struct PointsData {
		cv::Point p1; // top left
		cv::Point p2; // top right
		cv::Point p3; // bottom left
		cv::Point p4; // bottom right
	};


	/// <summary>
	/// Holds the raw videocapture corner coordinates of the field
	/// </summary>
	PointsData rawCorners;


	/// <summary>
	/// Projection matrix to normalize the videocapture image
	/// </summary>
	cv::Mat projectionMatrix;

	std::vector<IDetector*> detectors;

public:

	/// <summary>
	/// Add the detector to the List of the Detectors
	/// </summary>
	/// <param name="detector">the Detector to add</param>
	void addDetector(IDetector* detector);


	/// <summary>
	/// Detects the four corners of the Field and saves to <see cref="Field::rawCorners"/>, when all the corners are detected 
	/// </summary>
	/// <param name="img">Raw image capture</param>
	void initFieldNormalization(cv::Mat& img);


	/// <summary>
	/// Normalizes the videocapture using <see cref="projectionMatrix", outputs the normalized image to <see cref="fieldImage">
	/// </summary>
	void normalizeField();


	/// <summary>
	/// Updates every detector attached to the field and calls <see cref="normalizeField()">
	/// </summary>
	void update();
};
