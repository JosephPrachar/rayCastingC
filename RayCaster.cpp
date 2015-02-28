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

	while (curY > this->mView.y_min){
		Color result = this->castRay();
		this->printColor(outputFile, result);
		//*outputFile << "x: " << this->curX << " y: " << this->curY << "\n";
		this->advanceCastPoint();
	}

}

void RayCaster::printColor(ofstream* outputFile, Color toPrint){
	toPrint.scaleForPrinting();
	*outputFile << toPrint.getRed() << " " << toPrint.getGreen() << " " << toPrint.getBlue() << "\n";
}

Color RayCaster::castRay(){
	Color toReturn = Color(1.0, 1.0, 1.0);

	Point pt = Point(curX, curY, 0);
	Vector v = Point::vectorFromTo(this->mEye, pt);
	Ray ray = Ray(pt, v);
	
	int length = -1;
	Intersection* hitPoints = this->findIntersectionPoints(ray, &length);

	if (length != 0){
		toReturn.scale(0);
	}

	delete[] hitPoints;
	return toReturn;
}

Intersection* RayCaster::findIntersectionPoints(Ray ray, int* lengthOfArray){
	LinkedList<Intersection> list = LinkedList<Intersection>(Intersection(this->mSphereList[0], ray.getPoint()));

	for (int i = 0; i < this->mListLength; ++i){
		bool hit = false;
		Point pt = this->mSphereList[i].rayIntersection(ray, &hit);
		if (hit == true){
			list.add(Intersection(this->mSphereList[i], pt));
		}
	}

	*lengthOfArray = list.getLength();
	return list.toArray();
}

void RayCaster::advanceCastPoint(){
	this->curX += this->mView.delta_x;
	if (this->curX >= this->mView.x_max){
		this->curX = this->mView.x_min;
		this->curY -= this->mView.delta_y;
	}
}

