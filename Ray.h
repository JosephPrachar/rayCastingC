#pragma once
#include "stdafx.h"

class Ray{
public:
	Ray(Point pt, Vector dir);
	
	Point getPoint() const;
	Vector getDirection() const;

private:
	Point mPoint;
	Vector mDir;
};

inline bool operator==(const Ray& lhs, const Ray& rhs){
	return lhs.getPoint() == rhs.getPoint() &&
		lhs.getDirection() == rhs.getDirection();
}
inline bool operator!=(const Ray& lhs, const Ray& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Ray& obj);