#include "stdafx.h"

Finish::Finish(float ambient, float diffuse, float specular, float roughness){
	this->mAmbient = ambient;
	this->mDiffuse = diffuse;
	this->mSpecular = specular;
	this->mRough = roughness;	
}

float Finish::getAmbient(){
	return this->mAmbient;
}
float Finish::getDiffuse(){
	return this->mDiffuse;
}
float Finish::getSpecular(){
	return this->mSpecular;
}
float Finish::getRoughness(){
	return this->mRough;
}

bool Finish::operator==(Finish& rhs){
	return eEqual(this->mAmbient, rhs.mAmbient) &&
		eEqual(this->mDiffuse, rhs.mDiffuse) &&
		eEqual(this->mRough, rhs.mRough) &&
		eEqual(this->mSpecular, rhs.mSpecular);
}
bool operator!=(Finish& lhs, Finish& rhs){
	return !(lhs == rhs);
}

Finish Finish::copy(){
	return Finish(mAmbient, mDiffuse, mSpecular, mRough);
}