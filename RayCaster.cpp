#include "stdafx.h"
using namespace std;

RayCaster::RayCaster(Window view, Point eyePoint, Sphere* sphereList, int listLength, Color ambientColor, Light pointLight):
	mView(view),
	mEye(eyePoint),
	mSphereList(sphereList),
	mAmbient(ambientColor),
	mPointLight(pointLight)
{
	this->mListLength = listLength;

	this->curX = mView.x_min;
	this->curY = mView.y_max;
}

void RayCaster::castAllRays(ofstream* outputFile){
	long size = mView.width * mView.height * 3;
	byte* picture = new byte[size];
	Intersection* hitPointMem = new Intersection[this->mListLength];

	long count = 0;

	while (count < size){
		Color result = this->castRay(hitPointMem);
		result.scaleForPrinting();

		picture[count] = (byte)result.getRed();
		count++;
		picture[count] = (byte)result.getGreen();
		count++;
		picture[count] = (byte)result.getBlue();
		count++;

		// this->printColor(outputFile, result);	// lol system calls are expensive...
		this->advanceCastPoint();
	}

	this->printPicture(outputFile, picture);

	delete[] hitPointMem;
	delete[] picture;
}

void RayCaster::printPicture(ofstream* outputFile, byte* pic){
	long size = mView.width * mView.height * 3;	

	for (int i = 0; i < size; ++i){
		*outputFile << (int)pic[i] << ' ';
	}

	//*outputFile << toPrint.getRed() << " " << toPrint.getGreen() << " " << toPrint.getBlue() << "\n";
}

Color RayCaster::castRay(Intersection* hitPointMem){
	Color toReturn = Color(1.0, 1.0, 1.0);

	Point pt = Point(curX, curY, 0);
	Vector v = Point::vectorFromTo(this->mEye, pt);
	Ray ray = Ray(pt, v);
	
	int length = this->findIntersectionPoints(ray, hitPointMem);

	if (length != 0){
		toReturn.scale(0);
	}

	return toReturn;
}

int RayCaster::findIntersectionPoints(Ray ray, Intersection* hitPointMem){	
	int count = 0;
	for (int i = 0; i < this->mListLength; ++i){
		bool hit = false;
		Point pt = this->mSphereList[i].rayIntersection(ray, &hit);
		if (hit == true){
			hitPointMem[count] = Intersection(this->mSphereList[i], pt);
			count++;
		}
	}

	return count;
}

void RayCaster::advanceCastPoint(){
	this->curX += this->mView.delta_x;
	if (this->curX >= this->mView.x_max){
		this->curX = this->mView.x_min;
		this->curY -= this->mView.delta_y;
	}
}

