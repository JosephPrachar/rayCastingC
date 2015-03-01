#include "stdafx.h"

Color::Color(float red, float green, float blue){
	this->red = red;
	this->green = green;
	this->blue = blue;
}

float Color::getRed(){
	return this->red;
}
float Color::getGreen(){
	return this->green;
}
float Color::getBlue(){
	return this->blue;
}

void Color::scale(float value){
	this->red *= value;
	this->green *= value;
	this->blue *= value;
}
void Color::capValue(){
	if (this->red > 1)
		this->red = 1;
	if (this->green > 1)
		this->green = 1;
	if (this->blue > 1)
		this->blue = 1;
}

bool Color::operator==(Color& rhs){
	return eEqual(this->red, rhs.red) &&
		eEqual(this->green, rhs.green) &&
		eEqual(this->blue, rhs.blue);
}
bool Color::operator!=(Color& rhs){
	return !(*this == rhs);
}
//Color& Color::operator+(const Color& rhs){
//	this->red += rhs.red;
//	this->green += rhs.green;
//	this->blue += rhs.blue;
//	return *this;
//}
//Color& Color::operator*(const Color& rhs){
//	this->red *= rhs.red;
//	this->green *= rhs.green;
//	this->blue *= rhs.blue;
//	return *this;
//}

void Color::scaleForPrinting(){
	this->capValue();
	this->scale(Color::MAX_VALUE);
	this->red = (int)red;
	this->green = (int)green;
	this->blue = (int)blue;
}

void Color::multiply(Color toMult){
	this->red *= toMult.red;
	this->green *= toMult.green;
	this->blue *= toMult.blue;
}
void Color::add(Color toAdd){
	this->red += toAdd.red;
	this->green += toAdd.green;
	this->blue += toAdd.blue;
}
Color Color::copy(){
	return Color(this->red, this->green, this->blue);
}