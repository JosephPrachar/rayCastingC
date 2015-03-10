// RayCasting.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
using namespace std;

void printHeader(ofstream* myFile, int width, int height);
Sphere* readFile(std::string file, int* length);
Sphere parseSphere(std::string line, bool* good);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

int _tmain(int argc, _TCHAR* argv[])
{
	Window view = Window(-10, 10, -7.5, 7.5, 1024, 768);
	Point eye = Point(0,0,-14);
	int length = 0;
	Sphere* spheres = readFile("input.in", &length);
	Color ambientColor = Color(1, 1, 1);
	Light pointLight = Light(Point(-100, 100, -100), Color(1.5, 1.5, 1.5));

	RayCaster rc = RayCaster(view, eye, spheres, length, ambientColor, pointLight);

	ofstream myFile;
	myFile.open("image.ppm");
	cout<< length;
	printHeader(&myFile, view.width, view.height);
	rc.castAllRays(&myFile);

	myFile.close();

}

void printHeader(ofstream* myFile, int width, int height){
	*myFile << "P3\n";
	*myFile << width << ' ' << height;
	*myFile << "\n255\n";
}

Sphere* readFile(std::string file, int* length){
	std::vector<Sphere> list;
	string line;

	std::ifstream f(file);
	int count = 0;
	if (f.is_open()){
		while(getline(f, line)){
			bool good = false;
			Sphere temp = parseSphere(line, &good);

			if (good == true){
				list.push_back(temp);
			}
		}
		f.close();
	}

	*length = list.size();
	Sphere* toReturn = new Sphere[*length];
	for (int i = 0; i < *length; ++i){
		toReturn[i] = list[i].copy();
	}
	list.~vector();

	return toReturn;
}

Sphere parseSphere(std::string line, bool* good){
	vector<string> chars = split(line, ' ');
	
	if (chars.size() == 11){
		float vals[11];
		for (int i = 0; i < 11; ++i){
			vals[i] = std::stof(chars[i]);
			//cout << vals[i] << ' ';
		}
		//cout << "\n";
		*good = true;
		return Sphere(Point(vals[0], vals[1], vals[2]), vals[3], Color(vals[4], vals[5], vals[6]), Finish(vals[7], vals[8], vals[9], vals[10]));
	}
	
	*good = false;
	return Sphere();
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}