#pragma once
#include "stdafx.h"

class Color{
public:
	Color(float red, float green, float blue);
	Color();

	static const int MAX_VALUE = 255;

	float getRed() const;
	float getGreen() const;
	float getBlue() const;

	void scale(float value);
	void scaleForPrinting();
	void multiply(Color toMult);
	void add(Color toAdd);
	Color copy();
private:
	float red;
	float green;
	float blue;

	void capValue();
};

inline bool operator==(const Color& lhs, const Color& rhs){
	return eEqual(lhs.getRed(),rhs.getRed()) &&
		eEqual(lhs.getGreen(), rhs.getGreen()) &&
		eEqual(lhs.getBlue(), rhs.getBlue());
}
inline bool operator!=(const Color& lhs, const Color& rhs){
	return !(lhs == rhs);
}

// For unit testing
std::wstringstream& operator<<(std::wstringstream& os, const Color& obj);