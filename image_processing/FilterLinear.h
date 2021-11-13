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
	class FilterLinear : public Filter {
	protected:
		Color a;
		Color c;
	public:
		
		FilterLinear(Color A, Color C) {
			this->a = A;
			this->c = C;
		}
		
		FilterLinear(const FilterLinear & f) {
			this->a = f.a;
			this->c = f.c;
		}

		Image operator << (const Image& image) {
			Image f_image = image;
			vector <Color>* v = (vector<Color>*)f_image.getRawDataPtr();

			for (int i = 0; i < v->size(); i++) {
				v->at(i).x = a.x * v->at(i).x + c.x;
				v->at(i).y = a.y * v->at(i).y + c.y;
				v->at(i).z = a.z * v->at(i).z + c.z;
			}
			return f_image;
		}
	};
}