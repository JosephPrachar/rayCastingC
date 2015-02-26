#include "stdafx.h"

Ray::Ray(Point pt, Vector dir):
	mPoint(pt),
	mDir(dir)
{
}

Point Ray::getPoint(){
	return this->mPoint;
}
Vector Ray::getDirection(){
	return this->mDir;
}

bool Ray::operator==(Ray& rhs){
	return (this->mDir == rhs.mDir) &&
		(this->mPoint == rhs.mPoint);
}
bool Ray::operator!=(Ray& rhs){
	return !(*this == rhs);
}