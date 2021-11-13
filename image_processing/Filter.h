#pragma once
#include "array2d.hpp"
#include"array2d.h"
#include"imageio.h"
#include"vec3.h"
#include "Image.h"
#include <iostream>
#include "ppm.h"
using namespace math;
namespace image {
	class Filter {
	public:
		virtual Image operator << (const Image& image)=0;

		Filter() {}

		Filter(const Filter & f) {}
	};
}

