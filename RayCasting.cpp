// RayCasting.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
using namespace std;

void printHeader(ofstream* myFile, int width, int height);

void readSetupFile(std::string file, Window* view, Point* eye, Color* ambient, Light* light);
Sphere* readSphereFile(std::string file, int* length);

Sphere parseSphere(std::string line, bool* good);
Window parseWindow(std::string line, bool* good);
Point parsePoint(std::string line, bool* good);
Light parseLight(std::string line, bool* good);
Color parseColor(std::string line, bool* good);
vector<float> parseFloats(std::string line, int expected);

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

int _tmain(int argc, _TCHAR* argv[])
{
	Window view = Window(0,0,0,0,0,0);
	Point eye = Point(0,0,0);
	Color ambientColor = Color(0,0,0);
	Light pointLight = Light(Point(0,0,0), Color(0,0,0));

	readSetupFile("setup.in", &view, &eye, &ambientColor, &pointLight);
	
	int length = 0;
	Sphere* spheres = readSphereFile("input.in", &length);

	RayCaster rc = RayCaster(view, eye, spheres, length, ambientColor, pointLight);

	ofstream myFile;
	myFile.open("image.ppm");

	printHeader(&myFile, view.width, view.height);
	rc.castAllRays(&myFile);

	myFile.close();
}

void printHeader(std::ofstream* myFile, int width, int height){
	*myFile << "P3\n";
	*myFile << width << ' ' << height;
	*myFile << "\n255\n";
}

void readSetupFile(std::string file, Window* view, Point* eye, Color* ambient, Light* light){
	string line;
	bool good = true;

	std::ifstream f(file);

	if (f.is_open()){
		getline(f, line);
		*view = parseWindow(line, &good);

		getline(f, line);
		*eye = parsePoint(line, &good);

		getline(f, line);
		*ambient = parseColor(line, &good);

		getline(f, line);
		*light = parseLight(line, &good);
	}

	f.close();
}
Sphere* readSphereFile(std::string file, int* length){
	std::vector<Sphere> list;
	std::string line;

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
	vector<float> vals = parseFloats(line, 11);
	if (vals.size() != 0){
		*good = true;
		return Sphere(Point(vals[0], vals[1], vals[2]), vals[3], Color(vals[4], vals[5], vals[6]), Finish(vals[7], vals[8], vals[9], vals[10]));
	}

	*good = false;
	return Sphere();
}
Window parseWindow(std::string line, bool* good){
	vector<float> vals = parseFloats(line, 6);
	if (vals.size() != 0){
		*good = true;
		return Window(vals[0], vals[1], vals[2], vals[3], (int)vals[4], (int)vals[5]);
	}

	*good = false;
	return Window(0,0,0,0,0,0);
}
Point parsePoint(std::string line, bool* good){
	vector<float> vals = parseFloats(line, 3);
	if (vals.size() != 0){
		*good = true;
		return Point(vals[0], vals[1], vals[2]);
	}

	*good = false;
	return Point(0,0,0);
}
Light parseLight(std::string line, bool* good){
		vector<float> vals = parseFloats(line, 6);
	if (vals.size() != 0){
		*good = true;
		return Light(Point(vals[0], vals[1], vals[2]), Color(vals[3], vals[4], vals[5]));
	}

	*good = false;
	return Light(Point(0,0,0), Color(0,0,0));
}
Color parseColor(std::string line, bool* good){
	vector<float> vals = parseFloats(line, 3);
	if (vals.size() != 0){
		*good = true;
		return Color(vals[0], vals[1], vals[2]);
	}

	*good = false;
	return Color(0,0,0);
}
vector<float> parseFloats(std::string line, int expected){
	vector<string> chars = split(line, ' ');
	vector<float> nums = vector<float>();

	if (chars.size() == expected){
		try{
			for (int i = 0; i < expected; ++i){
				float f = std::stof(chars[i]);
				nums.push_back(f);
			}
		}
		catch (invalid_argument e){
			return vector<float>();
		}
	}

	return nums;
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