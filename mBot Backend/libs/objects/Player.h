#pragma once

#include "Point.h"
#include <string>

struct Player {
    Point realPosition;
    Point normPosition;

    float radRotation;

    int id;

    std::string team;
};