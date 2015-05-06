#include "stdafx.h"

Vector::Vector(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector::Vector()
{
	Vector(0,0,0);
}

float Vector::getX() const{
	return this->x;
}
float Vector::getY() const{
	return this->y;
}
float Vector::getZ() const{
	return this->z;
}
float Vector::getLength(){
	updateLength();
	return this->mLength;
}

void Vector::normalize(){
	float factor = 1.0f / this->getLength();
	this->scale(factor);
}
void Vector::scale(float scalar){
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}
float Vector::dotWith(Vector other){
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}
Vector Vector::crossWith(Vector other){
	return Vector(y*other.z - z*other.y,
					z*other.x - x*other.z,
					x*other.y - y*other.x);
}
void Vector::subtract(Vector toSubtract){
	this->x -= toSubtract.x;
	this->y -= toSubtract.y;
	this->z -= toSubtract.z;
}
Vector Vector::copy(){
	return Vector(this->x, this->y, this->z);
}
void Vector::updateLength(){
	this->mLength = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

std::wstringstream& operator<<(std::wstringstream& os, const Vector& obj){
	os << '<' << obj.getX() << ", " << obj.getY() << ", " << obj.getZ() << '>';
	return os;
}