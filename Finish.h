#pragma once
#include "stdafx.h"

class Finish{
public:
	Finish(float ambient, float diffuse, float specular, float roughness);
	Finish();

	float getAmbient() const;
	float getDiffuse() const;
	float getSpecular() const;
	float getRoughness() const;

	Finish copy();
private:
	float mAmbient;
	float mDiffuse;
	float mSpecular;
	float mRough;
};

inline bool operator==(const Finish& lhs, const Finish& rhs){
	return eEqual(lhs.getAmbient(), rhs.getAmbient()) &&
		eEqual(lhs.getDiffuse(), rhs.getDiffuse()) &&
		eEqual(lhs.getSpecular(), rhs.getSpecular()) &&
		eEqual(lhs.getRoughness(), rhs.getRoughness());
}
inline bool operator!=(const Finish& lhs, const Finish& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Finish& obj);