#pragma once
#include "stdafx.h"
using namespace std;

class Window{
public:
	Window(float x_min, float x_max, float y_min, float y_max, int width, int height);

	float x_min;
	float x_max;
	float delta_x;

	float y_min;
	float y_max;
	float delta_y;

	int width;
	int height;
};

std::wstringstream& operator<<(std::wstringstream& os, const Window& obj);