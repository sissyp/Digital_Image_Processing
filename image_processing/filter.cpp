#include "ppm.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	int width = 1200;
	int height = 750;
	int* w = &width;
	int* h = &height;
	float* data = image::ReadPPM("Image01.ppm", w, h);
	bool saved = image::WritePPM(data, width, height, "image.ppm");
	return 0;
}