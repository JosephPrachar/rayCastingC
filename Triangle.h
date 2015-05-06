#pragma once
#include "shape.h"
class Triangle : public Shape {
public:
	Triangle(Point points[3], Color color, Finish finish);
	Triangle();

	Point* getPoints() const;

	Point rayIntersection(Ray toIntersect, bool* hitsTriangle);
	bool triangleIntersection(Ray toIntersect, float* out);
	Vector normalAtPoint(Point pt);
	Triangle* copy();

private:
	Point* mPoints;
	Vector mNormal;

	void computeNormal();
};

