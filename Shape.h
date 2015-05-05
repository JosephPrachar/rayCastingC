#pragma once
#include "stdafx.h"

class Shape
{
protected:
	Color mColor;
	Finish mFinish;
public:
	Shape(Color color, Finish finish);

	Color getColor() const;
	Finish getFinish() const;

	virtual Point rayIntersection(Ray toIntersect, bool* hitsSphere) = 0;
	virtual Vector normalAtPoint(Point pt) = 0;

	virtual Shape* copy() = 0;
};

