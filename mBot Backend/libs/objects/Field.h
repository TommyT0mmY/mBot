#pragma once

#include "Point.h"

struct Field {
    Point realPoint1; // top left
    Point realPoint2; // top right
    Point realPoint3; // bottom left
    Point realPoint4; // bottom right

    Point normPoint1; // top left
    Point normPoint2; // top right
    Point normPoint3; // bottom left
    Point normPoint4; // bottom right

    float realHeight;
    float realWidth;

    float normHeight;
    float normWidth;
};