#include "stdafx.h"

class Light{
public:
	Light(Point pt, Color color);

	Point getPoint();
	Color getColor();

private:
	Point mPoint;
	Color mColor;
};