#pragma once
#include "stdafx.h"

class Shape
{
public:
	virtual Color getColor() const = 0;
	virtual Finish getFinish() const = 0;

	virtual Point rayIntersection(Ray toIntersect, bool* hitsSphere) = 0;
	virtual Vector normalAtPoint(Point pt) = 0;

	virtual Shape* copy() = 0;
};

