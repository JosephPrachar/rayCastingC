#pragma once
#include "stdafx.h"
using namespace std;

class RayCaster{
public:
	RayCaster(Window view, Point eyePoint, Sphere* sphereList, int listLength, Color ambientColor, Light pointLight);

	Color castRay();
	void castAllRays(ofstream* outputFile); // pass some sort of file stream

private:
	float curX;
	float curY;

	Window mView;
	Point mEye;
	Sphere* mSphereList;
	int mListLength;
	Color mAmbient;
	Light mPointLight;
	
	Intersection* findIntersectionPoints(Ray ray, int* lengthOfArray);

	Color computeAmbientLight(Sphere sphere);
	Color computePointAndSpecular(Point intersect, Sphere sphere);

	void advanceCastPoint();
	void printColor(ofstream* outputFile, Color toPrint);
};
