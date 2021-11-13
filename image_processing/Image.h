#pragma once
#include "array2d.hpp"
#include"array2d.h"
#include"imageio.h"
#include"vec3.h"
#include <iostream>
#include <string>
#include"ppm.h"
using namespace math;
typedef math::Vec3<float>  Color;
namespace image {
	class Image : public ImageIO, public Array2D <Color> {
	public:
		bool load(const std::string& filename, const std::string& format) {
			char char_array[sizeof(filename)];
			strcpy(char_array, filename.c_str());
			int w = (int)Array2D::width;
			int h = (int)Array2D::height;
			float* data = image::ReadPPM(char_array, &w, &h);
			if (format != "ppm") {
				std::cout << "file type must be ppm" << std::endl;
				exit(EXIT_FAILURE);
			}

			for (int i = 0; i < sizeof(data); i += 3) {
				Array2D::buffer[i].x = data[i];
				Array2D::buffer[i + 1].y = data[i + 1];
				Array2D::buffer[i + 2].z = data[i + 2];
			}
			bool done;
			if (Array2D::buffer.empty())
				done = false;
			else
				done = true;
			return done;
		}

		bool save(const std::string& filename, const std::string& format) {
			if (format != "ppm") {
				std::cout << "file type must be ppm" << std::endl;
				exit(EXIT_FAILURE);
			}
			float* data2 = new float[sizeof(buffer)];
			for (int i = 0; i < sizeof(buffer); i += 3) {
				data2[i] = Array2D::buffer[i].x;
				data2[i + 1] = Array2D::buffer[i + 1].y;
				data2[i + 2] = Array2D::buffer[i + 2].z;
			}
			char char_array[sizeof(filename)];
			strcpy(char_array, filename.c_str());
			bool s = image::WritePPM(data2, Array2D::width, Array2D::height, char_array);
			return s;
		}
	};
}
