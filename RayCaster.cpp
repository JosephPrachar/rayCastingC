#include "stdafx.h"

RayCaster::RayCaster(Window view, Point eyePoint, Shape** shapeList, int listLength, Color ambientColor, Light pointLight):
	mView(view),
	mEye(eyePoint),
	mShapeList(shapeList),
	mAmbient(ambientColor),
	mPointLight(pointLight)
{
	this->mListLength = listLength;

	this->curX = mView.x_min;
	this->curY = mView.y_max;

	this->computeTime = -1;
}

void RayCaster::castAllRays(ofstream* outputFile){
	std::clock_t start;
	start = std::clock();

	// calculate total size of buffer
	long size = mView.width * mView.height * 3;
	// allocate buffer
	byte* picture = new byte[size];
	// allocate memory for findIntersectionPoints
	Intersection* hitPointMem = new Intersection[this->mListLength];

	// check for valid memory allocation
	if (hitPointMem == NULL || picture == NULL){
		exit(1);
	}

	// for the console 'progress bar'
	long count = 0;
	float percent = .02f;

	while (count < size){
		Color result = this->castRay(hitPointMem);
		result.scaleForPrinting();

		// fill buffer with current pixel info
		picture[count] = (byte)result.getRed();
		count++;
		picture[count] = (byte)result.getGreen();
		count++;
		picture[count] = (byte)result.getBlue();
		count++;

		this->advanceCastPoint();

		// for the console 'progress bar'
		if (count % 1000 == 0 || count % 1000 == 1 || count % 1000 == 2){
			if ((float)count / (float)size > percent){
				std::cout << '=';
				percent += .02;
			}
		}
	}

	this->computeTime = (std::clock() - start)/(double)CLOCKS_PER_SEC;

	std::cout << "Done Computing";

	// output buffer to file
	this->printPicture(outputFile, picture);

	// free memory
	delete[] hitPointMem;
	delete[] picture;
}

void RayCaster::printPicture(ofstream* outputFile, byte* pic){
	long size = mView.width * mView.height * 3;
	// maximum size of buffer if all rgb color components are 4 chars "255 "
	char* buffer = new char[size * 4];

	// keep track of current writing position
	long pos = 0;
	for (int i = 0; i < size; ++i){
		// convert from numerical value to string
		std::string nums = std::to_string((int)pic[i]);
		// transfer to 'buffer'
		for (int j = 0; j < nums.length(); ++j){
			buffer[pos] = nums[j];
			pos++;
		}
		buffer[pos] = ' ';
		pos++;

	}

	// write buffer to outputFile
	outputFile->write(buffer, pos);
}

void RayCaster::byteDecompose(byte num, char* toFill){
	// old method to convert a byte to the string val
	// I figured that somebody a lot better at c++ wrote std::to_string()
	// so I switched to the use of that function

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
	Ray ray = Ray(this->mEye, v);
	
	int length = this->findIntersectionPoints(ray, hitPointMem);

	if (length != 0){ // hits a sphere
		int iSmall = 0;
		if (length > 1){ // if length is not greater than 1 no need to find shortest
			iSmall = this->shortestDistFromPoint(hitPointMem, length);
		}
		// extract closest intersection point so that hitPointsMem can be reused in findIntersectionPoints call by the specular color computation
		Intersection intersect = hitPointMem[iSmall].copy();		

		Color ambientColorAddition = this->computeAmbientLight(intersect.mShape);
		Color pointLighting = computePointAndSpecular(intersect, hitPointMem);
		ambientColorAddition.add(pointLighting);

		toReturn = ambientColorAddition;
	}

	return toReturn;
}

int RayCaster::shortestDistFromPoint(Intersection* hitPoints, int length){
	int iSmall = 0;
	float distSmall = this->mEye.distance(hitPoints[0].mPoint);

	for (int i = 1; i < length; ++i){
		float cur = this->mEye.distance(hitPoints[i].mPoint);
		if (cur < distSmall){
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
		Point pt = this->mShapeList[i]->rayIntersection(ray, &hit);
		if (hit == true){
			hitPointMem[count] = Intersection(this->mShapeList[i], pt);
			count++;
		}		
	}
	return count;
}

Color RayCaster::computeAmbientLight(Shape* shape){
	Color toReturn = shape->getColor().copy();
	toReturn.multiply(this->mAmbient);
	toReturn.scale(shape->getFinish().getAmbient());
	return toReturn;
}

Color RayCaster::computePointAndSpecular(Intersection intersect, Intersection* hitPointMem){
	// do math...

	Vector normal = intersect.mShape->normalAtPoint(intersect.mPoint);
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

	float dotTimesDiffuse = lDotN * intersect.mShape->getFinish().getDiffuse();
	Color pointColor = intersect.mShape->getColor().copy();
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
		float scale = intersect.mShape->getFinish().getSpecular() * pow(specIntense, (1.0 / intersect.mShape->getFinish().getRoughness()));
		specColor = this->mPointLight.getColor().copy();
		specColor.scale(scale);
	}

	pointColor.add(specColor);
	return pointColor;
}

void RayCaster::advanceCastPoint(){
	// move current point to next pixel
	this->curX += this->mView.delta_x;
	if (this->curX >= this->mView.x_max){
		this->curX = this->mView.x_min;
		this->curY -= this->mView.delta_y;
	}
}

