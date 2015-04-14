#pragma once
#include "stdafx.h"

class RayCaster {
public:
	RayCaster(Window view, Point eyePoint, Sphere* sphereList, int listLength, Color ambientColor, Light pointLight);

	Color castRay(Intersection* hitPointMem);
	void castAllRays(ofstream* outputFile); // pass some sort of file stream

	double computeTime;
private:
	float curX;
	float curY;

	Window mView;
	Point mEye;
	Sphere* mSphereList;
	int mListLength;
	Color mAmbient;
	Light mPointLight;
	
	int findIntersectionPoints(Ray ray, Intersection* hitPointMem);

	Color computeAmbientLight(Sphere sphere);
	Color computePointAndSpecular(Intersection intersect, Intersection* hitPointMem);

	void advanceCastPoint();
	void printPicture(ofstream* outputFile, byte* pic);
	void byteDecompose(byte num, char* toFill);

	int shortestDistFromPoint(Intersection* hitPoints, int length);
};
