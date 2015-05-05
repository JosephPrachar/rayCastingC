#pragma once
#include "stdafx.h"

Shape::Shape(Color color, Finish finish):
	mColor(color),
	mFinish(finish)
{

}

Color Shape::getColor() const{
	return this->mColor;
}
Finish Shape::getFinish() const{
	return this->mFinish;
}