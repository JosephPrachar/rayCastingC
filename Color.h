#include "stdafx.h"

class Color{
public:
	Color(float red, float green, float blue, int maxValue);

	float getRed();
	float getGreen();
	float getBlue();

	Color& operator +(const Color& rhs);
	Color& operator *(const Color& rhs);

	void scale(float value);
	void scaleForPrinting();
private:
	float red;
	float green;
	float blue;
	float mMaxValue;

	void capValue();
}