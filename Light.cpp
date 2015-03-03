#include "stdafx.h"

Light::Light(Point pt, Color color):
	mPoint(pt),
	mColor(color)
{
}

Point Light::getPoint() const{
	return this->mPoint;
}
Color Light::getColor() const{
	return this->mColor;
}

std::wstringstream& operator<<(std::wstringstream& os, const Light& obj){
	os << '(' << &obj.getPoint() << ', ' << &obj.getColor() << ')';
	return os;
}