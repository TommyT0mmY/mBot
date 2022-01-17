#pragma once

#include "Field.h"

class Ball : protected Field {
	int x, y;


	/// <summary>
	/// Updates the ball position from a normalized image
	/// </summary>
	void updatePosition();
};