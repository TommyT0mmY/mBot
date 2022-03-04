#pragma once

#include <opencv2/core/core.hpp>

class ImageNormalizer
{
public:
	void setRawImage(cv::Mat* rawImage);

	cv::Mat getNormalizedImage() const;

	void initNormalization();
	void normalize();

private:
	/// <summary>
	/// Puntatore alla video capture non normalizzata
	/// </summary>
	cv::Mat* rawImage_p;

	/// <summary>
	/// Immagine normalizzata utlilizzando <see cref="projectionMatrix"/>
	/// </summary>
	cv::Mat normalizedImage;

	/// <summary>
	/// Matrice di proiezione per normalizzare l'immagine
	/// </summary>
	cv::Mat projectionMatrix;
};

