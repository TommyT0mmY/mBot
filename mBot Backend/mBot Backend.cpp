// mBot Backend.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "mBot Backend.h"

#include <iostream>
#include <opencv2/highgui.hpp>



Backend::Backend(VideoFeed _videoFeed, ImageNormalizer _imageNormalizer)
	: videoFeed(_videoFeed),imageNormalizer(_imageNormalizer)
{
	std::cout << "backend constructor call\n";
}

DataTransfer Backend::update() {
	std::cout << "backend update call\n";

	//prendo l'immagine
	cv::Mat* rawImage = videoFeed.nextImage();

	//dai l'immagine non normalizzata al field detector
	fieldDetector.update(*rawImage);

	//prendi il field dal detector
	Field field = fieldDetector.getField();

	//schifo
	cv::Point2f src[] = {
		{field.realPoint1.x,field.realPoint1.y},
		{field.realPoint2.x,field.realPoint2.y},
		{field.realPoint3.x,field.realPoint3.y},
		{field.realPoint4.x,field.realPoint4.y},
	};

	imageNormalizer.setRawImage(rawImage);

	imageNormalizer.initNormalization(src);

	imageNormalizer.normalize();

	cv::Mat normalizerImage = imageNormalizer.getNormalizedImage();

	DataTransfer result;

	//result.image = videoFeed.nextImage();

	cv::imshow("Test", *videoFeed.getImage());
	cv::pollKey();

	return result;
}
