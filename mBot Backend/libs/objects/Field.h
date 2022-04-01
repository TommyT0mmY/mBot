#pragma once

#include "Point.h"

struct Field {
    Point realTopLeft;
    Point realTopRight;
    Point realBottomLeft;
    Point realBottomRight;

    Point normTopLeft;
    Point normTopRight;
    Point normBottomLeft;
    Point normBottomRight;

    float height;
    float width;
};
