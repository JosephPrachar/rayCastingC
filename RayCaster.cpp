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

		this->advanceCastPoint();
	}

	this->printPicture(outputFile, picture);

	delete[] hitPointMem;
	delete[] picture;
}

void RayCaster::printPicture(ofstream* outputFile, byte* pic){
	long size = mView.width * mView.height * 3;	
	char* buffer = new char[size * 4];

	long pos = 0;
	for (int i = 0; i < size; ++i){
		char nums[3];
		this->byteDecompose(pic[i], nums);
		for (int j = 0; j < 3; ++j){
			buffer[pos] = nums[j];
			pos++;
		}
		buffer[pos] = ' ';
		pos++;

	}
	outputFile->write(buffer, pos);
}

void RayCaster::byteDecompose(byte num, char* toFill){
	byte number = num;
	for (int i = 0; i < 3; ++i){
		int place = number / (100 / pow(10, i));
		toFill[i] = (char)(place + (int)'0');
		number -= place * (100 / pow(10, i));
	}
}

Color RayCaster::castRay(Intersection* hitPointMem){
	Color toReturn = Color(1.0, 1.0, 1.0);

	Point pt = Point(curX, curY, 0);
	Vector v = Point::vectorFromTo(this->mEye, pt);
	Ray ray = Ray(pt, v);
	
	int length = this->findIntersectionPoints(ray, hitPointMem);

	if (length != 0){
		int iSmall = this->shortestDistFromPoint(pt, hitPointMem, length);
		Intersection intersect = hitPointMem[iSmall].copy();	// extract intersection that matters so that hitPointsMem can be reused in specular color computation

		Color ambientColorAddition = this->computeAmbientLight(intersect.mSphere);
		Color pointLighting = computePointAndSpecular(intersect, hitPointMem);
		ambientColorAddition.add(pointLighting);

		toReturn = ambientColorAddition;
	}

	return toReturn;
}

int RayCaster::shortestDistFromPoint(Point source, Intersection* hitPoints, int length){
	int iSmall = 0;
	float distSmall = source.distance(hitPoints[0].mPoint);

	for (int i = 0; i < length; ++i){
		float cur = source.distance(hitPoints[i].mPoint);
		if (cur > distSmall){
			iSmall = i;
			distSmall = cur;
		}
	}
	
	return iSmall;
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

Color RayCaster::computeAmbientLight(Sphere sphere){
	Color toReturn = sphere.getColor().copy();
	toReturn.multiply(this->mAmbient);
	toReturn.scale(sphere.getFinish().getAmbient());
	return toReturn;
}

Color RayCaster::computePointAndSpecular(Intersection intersect, Intersection* hitPointMem){
	Vector normal = intersect.mSphere.normalAtPoint(intersect.mPoint);
	Vector scaledNormal = normal.copy();
	scaledNormal.scale(.01);

	Point pSubE = intersect.mPoint.copy();
	pSubE.translate(scaledNormal);

	Vector lSubDir = Point::vectorFromTo(pSubE, this->mPointLight.getPoint());
	lSubDir.normalize();

	float lDotN = normal.dotWith(lSubDir);

	if (lDotN <= 0){
		return Color(0,0,0);
	}

	Ray rayToLight = Ray(pSubE, lSubDir);

	int length = this->findIntersectionPoints(rayToLight, hitPointMem);

	if (length > 0){
		float distToLight = pSubE.distance(this->mPointLight.getPoint());
		for (int i = 0; i < length; ++i){
			if (pSubE.distance(hitPointMem[i].mPoint) < distToLight){
				return Color(0,0,0);
			}
		}
	}

	float dotTimesDiffuse = lDotN * intersect.mSphere.getFinish().getDiffuse();
	Color pointColor = intersect.mSphere.getColor().copy();
	pointColor.multiply(this->mPointLight.getColor());
	pointColor.scale(dotTimesDiffuse);

	Vector temp = normal.copy();
	temp.scale(2*lDotN);
	Vector reflect = lSubDir.copy();
	reflect.subtract(temp);

	Vector vSubDir = Point::vectorFromTo(this->mEye, pSubE);
	vSubDir.normalize();

	float specIntense = reflect.dotWith(vSubDir);
	Color specColor = Color(0,0,0);
	if (specIntense > 0){
		float scale = intersect.mSphere.getFinish().getSpecular() * pow(specIntense, (1.0 / intersect.mSphere.getFinish().getRoughness()));
		specColor = this->mPointLight.getColor().copy();
		specColor.scale(scale);
	}

	//pointColor.add(specColor);
	return pointColor;
}

void RayCaster::advanceCastPoint(){
	this->curX += this->mView.delta_x;
	if (this->curX >= this->mView.x_max){
		this->curX = this->mView.x_min;
		this->curY -= this->mView.delta_y;
	}
}

