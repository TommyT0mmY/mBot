#pragma once

#include "Point.h"
#include <string>

struct Player {
    Point position;
    float radRotation;
    int id;
    std::string team;
};