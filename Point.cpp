#include "stdafx.h"

Point::Point(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}
Point::Point(){
	Point(0,0,0);
}

float Point::getX() const{
	return this->x;
}
float Point::getY() const{
	return this->y;
}
float Point::getZ() const{
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
Vector Point::differenceVector(Point one, Point two){
	return Point::vectorFromTo(two, one);
}

std::wstringstream& operator<<(std::wstringstream& os, const Point& obj){
	os << '<' << obj.getX() << ", " << obj.getY() << ", " << obj.getZ() << '>';
	return os;
}