#pragma once

#include <opencv2/core/core.hpp>
#include "Detector.h"
#include "../objects/Field.h"


class FieldDetector : public IDetector {
private:
	Field field;


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
	/// Projection matrix to normalize the videocapture image.
	/// This matrix gets initialized by <see cref="Field::initFieldNormalization()"/>
	/// </summary>
	cv::Mat projectionMatrix;


public:
	void initFieldNormalization();


	/// <summary>
	/// Normalizes the videocapture using <see cref="projectionMatrix", outputs the normalized image to <see cref="fieldImage">
	/// </summary>
	void normalizeField();


	void update();


	Field getField();
};
