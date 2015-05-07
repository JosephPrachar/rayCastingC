#pragma once
#include "stdafx.h"
using namespace std;

class RayCaster {
public:
	RayCaster(Window view, Point eyePoint, std::vector<Shape*> shapeList, Color ambientColor, Light pointLight);

	Color castRay(Intersection* hitPointMem);
	void castAllRays(ofstream* outputFile); // pass some sort of file stream

	double computeTime;
private:
	float curX;
	float curY;

	Window mView;
	Point mEye;
	std::vector<Shape*> mShapeList;
	Color mAmbient;
	Light mPointLight;
	
	int findIntersectionPoints(Ray ray, Intersection* hitPointMem);

	Color computeAmbientLight(Shape* shape);
	Color computePointAndSpecular(Intersection intersect, Intersection* hitPointMem);

	void advanceCastPoint();
	void printPicture(ofstream* outputFile, byte* pic);
	void byteDecompose(byte num, char* toFill);

	int shortestDistFromPoint(Intersection* hitPoints, int length);
};
