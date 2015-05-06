#include "stdafx.h"

Sphere::Sphere(Point center, float radius, Color color, Finish finish):
	Shape(color, finish),
	mCenter(center)
{
	this->mRadius = radius;
}
Sphere::Sphere():
	Shape(Color(0,0,0),
	Finish(0,0,0,0)),
	mCenter(0,0,0)
{
	this->mRadius = 0;
}

Point Sphere::getCenter() const{
	return this->mCenter;
}
float Sphere::getRadius() const{
	return this->mRadius;
}

// overrides from shape
Point Sphere::rayIntersection(Ray toIntersect, bool* hitsSphere){
	// math

	float a = toIntersect.getDirection().dotWith(toIntersect.getDirection());
	Vector sphereToRay = Point::differenceVector(toIntersect.getPoint(), this->mCenter);
	float b = 2 * toIntersect.getDirection().dotWith(sphereToRay);
	float c = sphereToRay.dotWith(sphereToRay) - pow(this->mRadius, 2);


	float dis = pow(b, 2) - 4 * a * c;

	if (dis < 0){
		*hitsSphere = false;
		return Point(0,0,0);
	}
	

	float root = sqrt(dis);

	float oneRoot = (((-1 * b) + root)) / (2 * a);
	float otherRoot = (((-1 * b) - root)) / (2 * a);

	float t = -1;
	if (oneRoot >= 0 && otherRoot >= 0){
		t = otherRoot;
	}
	else if (oneRoot >= 0){
		t = oneRoot;
	}
	else {
		*hitsSphere = false;
		return Point(0,0,0);
	}

	*hitsSphere = true;
	Point pt = toIntersect.getPoint().copy();
	Vector trans = toIntersect.getDirection().copy();
	trans.scale(t);
	pt.translate(trans);
	return pt;
}
Vector Sphere::normalAtPoint(Point pt){
	Vector toReturn = Point::vectorFromTo(this->mCenter, pt);
	toReturn.normalize();
	return toReturn;
}

Sphere* Sphere::copy(){
	return new Sphere(mCenter.copy(), mRadius, mColor.copy(), mFinish.copy());
}

std::wstringstream& operator<<(std::wstringstream& os, const Sphere& obj){
	os << '(' << &obj.getCenter() << ', ' << obj.getRadius() << ', ' << &obj.getColor() << ', ' << &obj.getFinish() << ')';
	return os;
}