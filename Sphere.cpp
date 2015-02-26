#include "stdafx.h"

Sphere::Sphere(Point center, float radius, Color color, Finish finish):
	mCenter(center),
	mColor(color),
	mFinish(finish)
{
	this->mRadius = radius;
}

Point Sphere::getCenter(){
	return this->mCenter;
}
float Sphere::getRadius(){
	return this->mRadius;
}
Color Sphere::getColor(){
	return this->mColor;
}
Finish Sphere::getFinish(){
	return this->mFinish;
}

bool Sphere::operator==(Sphere& rhs){
	return (this->mCenter == rhs.mCenter) &&
		eEqual(this->mRadius, rhs.mRadius) &&
		(this->mColor == rhs.mColor) &&
		(this->mFinish == rhs.mFinish);
}
bool Sphere::operator!=(Sphere& rhs){
	return !(*this == rhs);
}

Point rayIntersection(Ray toIntersect){
	return Point(0,0,0);
}
Vector normalAtPoint(Point pt){
	return Vector(0,0,0);
}