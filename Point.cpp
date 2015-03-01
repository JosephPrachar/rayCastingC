#include "stdafx.h"

Point::Point(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

float Point::getX(){
	return this->x;
}
float Point::getY(){
	return this->y;
}
float Point::getZ(){
	return this->z;
}

void Point::translate(Vector toAdd){
	this->x += toAdd.getX();
	this->y += toAdd.getY();
	this->z += toAdd.getZ();
}
Point Point::copy(){
	return Point(this->x, this->y, this->z);
}
float Point::distance(Point other){
	return sqrt(this->distanceSquared(other));
}
float Point::distanceSquared(Point other){
	return pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2);
}

Vector Point::vectorFromTo(Point from, Point to){
	return Vector(to.x - from.x, to.y - from.y, to.z - from.z);
}

bool Point::operator==(Point& rhs){
	return eEqual(this->x, rhs.x) &&
		eEqual(this->y, rhs.y) &&
		eEqual(this->z, rhs.z);
}
bool Point::operator!=(Point& rhs){
	return !(*this == rhs);
}