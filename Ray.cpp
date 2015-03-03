#include "stdafx.h"

Ray::Ray(Point pt, Vector dir):
	mPoint(pt),
	mDir(dir)
{
}

Point Ray::getPoint() const{
	return this->mPoint;
}
Vector Ray::getDirection() const{
	return this->mDir;
}

std::wstringstream& operator<<(std::wstringstream& os, const Ray& obj){
	os << '(' << &obj.getPoint() << ', ' << &obj.getDirection() << ')';
	return os;
}