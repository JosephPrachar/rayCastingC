#include "stdafx.h"

Light::Light(Point pt, Color color):
	mPoint(pt),
	mColor(color)
{
}

Point Light::getPoint(){
	return this->mPoint;
}
Color Light::getColor(){
	return this->mColor;
}