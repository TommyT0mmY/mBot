#pragma once

#include "Point.h"

struct Field {
    Point realPoint1; // top left
    Point realPoint2; // top right
    Point realPoint3; // bottom left
    Point realPoint4; // bottom right
    float realHeight;
    float realWidth;
};