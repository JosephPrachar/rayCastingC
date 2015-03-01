#include "stdafx.h"

Intersection::Intersection(Sphere sphere, Point point):
	mSphere(sphere),
	mPoint(point)
{

}
Intersection::Intersection():
	mSphere(Point(.5, 1.5, -3), .5, Color(1, 0, 0), Finish(.4, .4, .5, .05)),
	mPoint(0,0,0)
{
}

Intersection Intersection::copy(){
	return Intersection(mSphere.copy(), mPoint.copy());
}