#include "stdafx.h"
#include "Triangle.h"

#define EPSILON .000001

Triangle::Triangle(Point* points, Color color, Finish finish):
	Shape(color, finish),
	mPoints(points)
{
	computeNormal();
}
Triangle::Triangle():
	Shape(Color(), Finish()),
	mPoints(NULL)
{
}

Point* Triangle::getPoints() const{
	return this->mPoints;
}

Point Triangle::rayIntersection(Ray toIntersect, bool* hitsTriangle){
	float scalar = 0;
	*hitsTriangle = triangleIntersection(toIntersect, &scalar);

	if (*hitsTriangle){
		Vector scaled = toIntersect.getDirection().copy();
		scaled.scale(scalar);

		Point intersection = toIntersect.getPoint().copy();
		intersection.translate(scaled);
		return intersection;
	}

	return Point();
}
bool Triangle::triangleIntersection(Ray toIntersect, float* out){
	// Möller–Trumbore intersection algorithm
	// Translated from the C program posted on
	// the Wikipedia page of the same name at
	// http://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm

	Vector edge1, edge2;
	Vector P, Q, T;
	float det, inv_det, u, v;
	float t;

	edge1 = Point::differenceVector(this->mPoints[1], this->mPoints[0]);
	edge2 = Point::differenceVector(this->mPoints[2], this->mPoints[0]);

	P = toIntersect.getDirection().crossWith(edge2);
	det = edge1.dotWith(P);
	if (det >-EPSILON && det < EPSILON)
		return false;

	inv_det = 1.f / det;
	T =  Point::differenceVector(toIntersect.getPoint(), this->mPoints[0]);
	u = T.dotWith(P) * inv_det;
	if (u < 0.f || u > 1.f)
		return false;

	Q = T.crossWith(edge1);
	v = toIntersect.getDirection().dotWith(Q) * inv_det;
	if (v < 0.f || u + v > 1.f)
		return false;

	t = edge2.dotWith(Q) * inv_det;
	if (t > EPSILON){
		*out = t;
		return true;
	}

	return false;
}