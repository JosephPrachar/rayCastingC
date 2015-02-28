#pragma once
#include "stdafx.h"

class Intersection{
public:
	Intersection(Sphere sphere, Point point);
	Intersection();

	Sphere mSphere;
	Point mPoint;
};