#pragma once
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
	return;
}
void Vector::scale(float scalar){
	return;
}
float Vector::dotWith(Vector other){
	return -1;
}
void Vector::subtract(Vector toSubtract){
	return;
}