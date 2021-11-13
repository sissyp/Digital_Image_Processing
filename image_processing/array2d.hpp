#include "array2d.h"
#include <vector>
namespace math {
	template <typename T>
	class Array2D {
	protected:
		std::vector<T> buffer;
		unsigned int width, height;
		
	public:
		const unsigned int getWidth() const {
			return width;
		}

		const unsigned int getHeight() const {
			return height;
		}

		T* getRawDataPtr() {
			return buffer;
		}

		void setData(const T* const& data_ptr) {
			int size = 3 * width * height;

			for (int i = 0; i < size; i++) {
				buffer[i] = data_ptr[i];
			}
		}

		T& operator () (unsigned int x, unsigned int y) {
			return buffer[(width * y + x) * 3];
		}

		Array2D(unsigned int width = 0, unsigned int height = 0, const T* data_ptr = 0) {
			this.width = width;
			this.height = height;
			setData(data_ptr);
		}

		Array2D(const Array2D& src) :width(src.width), height(src.height), buffer(src.buffer) {}

		~Array2D() {
			delete[] buffer;
		}

		Array2D& operator = (const Array2D& right) {
			Array2D left = Array2D(right);
			return left;
		}
	};
}