#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>

class ImageNormalizer
{
public:
	void setRawImage(cv::Mat* rawImage);

	cv::Mat getNormalizedImage() const;

	/// <summary>
	/// Setta la matrice di proiezione in base ai quattro angoli dell'immagine
	/// </summary>
	/// <param name="I quattro angoli dell'immagine (qrcodes)"></param>
	void initNormalization(cv::Point2f src[]);

	/// <summary>
	/// Normalizza <see cref="rawImage_p"/> utilizzando <see cref="projectionMatrix"/>
	/// </summary>
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

	/// <summary>
	/// Altezza reale TODO
	/// </summary>
	const float height = 1024.f;

	/// <summary>
	/// Larghezza reale TODO
	/// </summary>
	const float width = 1024.f;
};

