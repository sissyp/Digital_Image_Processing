#pragma once
#include"imageio.h"
#include"vec3.h"
#include "Image.h"
#include "Filter.h"
#include <vector>
using namespace math;
using namespace std;
typedef math::Vec3<float>  Color;
namespace image {
	class FilterGamma : public Filter {
	protected:
		float gamma;
	public:
		FilterGamma(float g) {
			this->gamma = g;
		}

		Image operator << (const Image& image) {
			Image f_image = image;
			vector <Color>* v = (vector<Color>*)f_image.getRawDataPtr();

			for (int i = 0; i < v->size(); i++) {
				v->at(i).x = pow(v->at(i).x,gamma);
				v->at(i).y = pow(v->at(i).y,gamma);
				v->at(i).z = pow(v->at(i).z, gamma);
			}
			return f_image;
		}
	};
}
