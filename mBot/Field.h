#pragma once

#include <opencv2/core/core.hpp>

/// <summary>
/// Handles the game field
/// </summary>
class Field {


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
	
	
	/// <summary>
	/// Normalized image of the field
	/// Normalized using <see cref="projectionMatrix"/>
	/// </summary>
	cv::Mat fieldImage;


	/// <summary>
	/// Detects the four corners of the Field and saves to <see cref="Field::rawCorners"/>, when all the corners are detected 
	/// </summary>
	/// <param name="img">Raw image capture</param>
	void initFieldNormalization(cv::Mat& img);


	/// <summary>
	/// Normalizes the videocapture using <see cref="projectionMatrix", outputs the normalized image to <see cref="fieldImage">
	/// </summary>
	void normalizeField();
};
