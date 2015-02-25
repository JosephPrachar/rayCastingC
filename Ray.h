#include "stdafx.h"

class Ray{
public:
	Ray(Point from, Point to);
	Ray(Point pt, Vector dir);
	
	Point getPoint();
	Vector getDirection();
private:
	Point mPoint;
	Vector mDir;
}