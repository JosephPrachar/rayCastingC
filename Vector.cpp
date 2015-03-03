#include "stdafx.h"

Vector::Vector(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
	updateLength();
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
float Vector::getLength() const{
	return this->mLength;
}

void Vector::normalize(){
	float factor = 1.0f / this->mLength;
	this->scale(factor);
}
void Vector::scale(float scalar){
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	this->updateLength();
}
float Vector::dotWith(Vector other){
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}
void Vector::subtract(Vector toSubtract){
	this->x -= toSubtract.x;
	this->y -= toSubtract.y;
	this->z -= toSubtract.z;
	this->updateLength();
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