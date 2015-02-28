// RayCasting.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
using namespace std;

void printHeader(ofstream* myFile, int width, int height);

int _tmain(int argc, _TCHAR* argv[])
{
	Window view = Window(-10, 10, -7.5, 7.5, 1024, 768);
	Point eye = Point(0,0,-14);
	Sphere spheres[2] = { 
		Sphere(Point(.5, 1.5, -3), .5, Color(1, 0, 0), Finish(.4, .4, .5, .05)),
		Sphere(Point( 1,  1,   0),  2, Color(0, 0, 1), Finish(.2, .4, .5, .05)) 
	};
	Color ambientColor = Color(1, 1, 1);
	Light pointLight = Light(Point(-100, 100, -100), Color(1.5, 1.5, 1.5));

	RayCaster rc = RayCaster(view, eye, spheres, 2, ambientColor, pointLight);

	ofstream myFile;
	myFile.open("image.ppm");

	printHeader(&myFile, view.width, view.height);
	rc.castAllRays(&myFile);

	myFile.close();

}

void printHeader(ofstream* myFile, int width, int height){
	*myFile << "P3\n";
	*myFile << width << ' ' << height;
	*myFile << "\n255\n";
}