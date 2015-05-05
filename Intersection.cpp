#include "stdafx.h"

Intersection::Intersection(Shape* sphere, Point point):
	mShape(sphere),
	mPoint(point)
{

}
Intersection::Intersection():
	mPoint(0,0,0)
{
	mShape = &Sphere(Point(.5, 1.5, -3), .5, Color(1, 0, 0), Finish(.4, .4, .5, .05));
}

Intersection Intersection::copy(){
	return Intersection(mShape->copy(), mPoint.copy());
}

std::wstringstream& operator<<(std::wstringstream& os, const Intersection& obj){
	os << '{' << &obj.mShape << ', ' << &obj.mPoint << '}';
	return os;
}