#include "stdafx.h"

Window::Window(float x_min, float x_max, float y_min, float y_max, int width, int height){
	this->x_min = x_min;
	this->x_max = x_max;
	this->y_min = y_min;
	this->y_max = y_max;
	this->width = width;
	this->height = height;

	this->delta_x = (x_max - x_min) / float(width);
	this->delta_y = (y_max - y_min) / float(height);
}

std::wstringstream& operator<<(std::wstringstream& os, const Window& obj){
	os << '<' << obj.x_min << ", " << obj.x_max << ", " << obj.y_min << ", " << obj.y_max << ", " << obj.width << ", " << obj.height << '>'; 
	return os;
}