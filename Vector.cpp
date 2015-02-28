#include "stdafx.h"

Vector::Vector(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector::getX(){
	return this->x;
}
float Vector::getY(){
	return this->y;
}
float Vector::getZ(){
	return this->z;
}
float Vector::getLength(){
	return this->mLength;
}

bool Vector::operator==(Vector& rhs){
	return eEqual(this->x, rhs.x) &&
		eEqual(this->y, rhs.y) &&
		eEqual(this->z, rhs.z);
}
bool Vector::operator!=(Vector& rhs){
	return !(*this == rhs);
}

void Vector::normalize(){
	float factor = 1.0f / this->mLength;
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
void Vector::subtract(Vector toSubtract){
	this->x -= toSubtract.x;
	this->y -= toSubtract.y;
	this->z -= toSubtract.z;
}
Vector Vector::copy(){
	return Vector(this->x, this->y, this->z);
}