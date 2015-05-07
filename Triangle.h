#pragma once
#include "shape.h"
class Triangle : public Shape {
public:
	//Triangle(Point points[3], Color color, Finish finish);
	Triangle(Color color, Finish finish, Point one, Point two, Point three);
	Triangle();

	Point* getPoints() const;

	Point rayIntersection(Ray toIntersect, bool* hitsTriangle);
	bool triangleIntersection(Ray toIntersect, float* out);
	Vector normalAtPoint(Point pt);
	void alignNormalWithEyePt(Point eye);
	Triangle* copy();

private:
	Point mOne;
	Point mTwo;
	Point mThree;
	Vector mNormal;

	void computeNormal();
};

