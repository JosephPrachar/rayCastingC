#pragma once
#include "stdafx.h"

class Color{
public:
	Color(float red, float green, float blue);

	static const int MAX_VALUE = 255;

	float getRed();
	float getGreen();
	float getBlue();

	bool operator==(Color& rhs);
	bool operator!=(Color& rhs);
	Color& operator +(const Color& rhs);
	//Color& operator *(const Color& rhs);

	void scale(float value);
	void scaleForPrinting();
private:
	float red;
	float green;
	float blue;

	void capValue();
};