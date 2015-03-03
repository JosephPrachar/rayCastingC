#pragma once
#include "stdafx.h"

class Light{
public:
	Light(Point pt, Color color);

	Point getPoint() const;
	Color getColor() const;

private:
	Point mPoint;
	Color mColor;
};

inline bool operator==(const Light& lhs, const Light& rhs){
	return (lhs.getColor() == rhs.getColor()) && (lhs.getPoint() == rhs.getPoint());
}
inline bool operator!=(const Light lhs, const Light& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Light& obj);