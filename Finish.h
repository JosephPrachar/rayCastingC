#include "stdafx.h"

class Finish{
public:
	Finish(float ambient, float diffuse, float specular, float roughness);

	float getAmbient();
	float getDiffuse();
	float getSpecular();
	float getRoughness();

private:
	float mAmbient;
	float mDiffuse;
	float mSpecular;
	float mRough;
}