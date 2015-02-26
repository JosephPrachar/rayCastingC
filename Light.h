#pragma once
#include "stdafx.h"

class Light{
public:
	Light(Point pt, Color color);

	Point getPoint();
	Color getColor();

	bool operator==(Light& rhs);
	bool operator!=(Light& rhs);

private:
	Point mPoint;
	Color mColor;
};