#pragma once
#include "stdafx.h"

class Ray{
public:
	Ray(Point pt, Vector dir);
	
	Point getPoint();
	Vector getDirection();

	bool operator==(Ray& rhs);
	bool operator!=(Ray& rhs);
private:
	Point mPoint;
	Vector mDir;
};