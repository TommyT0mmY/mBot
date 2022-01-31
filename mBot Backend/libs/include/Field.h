#pragma once

#include "Detector.h"
#include <opencv2/core/core.hpp>

/// <summary>
/// Handles the game field
/// </summary>
class Field {
private:
	int normalizeWidth;
	int normalizeHeight;


	/// <summary>
	/// Four <see cref="cv::Point"/>
	/// </summary>
	struct PointsData {
		cv::Point2f p1; // top left
		cv::Point2f p2; // top right
		cv::Point2f p3; // bottom left
		cv::Point2f p4; // bottom right
	};


	/// <summary>
	/// Pointer to the raw video capture image
	/// </summary>
	cv::Mat* rawFieldImage_p;


	/// <summary>
	/// Normalized image of the field
	/// Normalized using <see cref="projectionMatrix"/>
	/// </summary>
	cv::Mat normalizedFieldImage;
	

	/// <summary>
	/// Holds the raw videocapture corner coordinates of the field
	/// </summary>
	PointsData rawCorners;


	/// <summary>
	/// Projection matrix to normalize the videocapture image.
	/// This matrix gets initialized by <see cref="Field::initFieldNormalization()"/>
	/// </summary>
	cv::Mat projectionMatrix;


	/// <summary>
	/// Detectors get updated from <see cref="Field::update()"/>
	/// </summary>
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
	void initFieldNormalization();


	/// <summary>
	/// Normalizes the videocapture using <see cref="projectionMatrix", outputs the normalized image to <see cref="fieldImage">
	/// </summary>
	void normalizeField();


	/// <summary>
	/// Updates every detector attached to the field and calls <see cref="normalizeField()">
	/// </summary>
	void update();
};
