#include "stdafx.h"
#include "Vector.h"

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

bool Point::operator==(Point& rhs){
	return eEqual(this->x, rhs.x) &&
		eEqual(this->y, rhs.y) &&
		eEqual(this->z, rhs.z);
}
bool Point::operator!=(Point& rhs){
	return !(*this == rhs);
}