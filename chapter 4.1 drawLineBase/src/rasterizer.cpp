#include "../include/rasterizer.h"

Rasterizer::Rasterizer()
{
}

Rasterizer::~Rasterizer()
{
}

// y = \frac{ y_1 - y_0 }{x_1 - x_0}x + \frac{ x_1y_0 - x_0y_1 }{x_1 - x_0}\tag{ 1.1 }
void Rasterizer::drawLineBase(Vector3f &vertex1, Vector3f &vertex2, const Uint32 &color, Buffer<Uint32> *pixelBuffer) {
	int x1 = vertex1.x;
	int y1 = vertex1.y;
	int x2 = vertex2.x;
	int y2 = vertex2.y;

	// 确保x1小于x2
	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	float k = 1.0*(y2 - y1) / (x2 - x1);
	float b = 1.0*(x2*y1 - x1*y2) / (x2 - x1);

	int x = x1 > 0 ? x1 : 0;
	for (; x <= x2 && x < pixelBuffer->mWidth; x++) {
		int y = 1.0*k*x + b;
		if (y < pixelBuffer->mHeight && y >= 0) {
			(*pixelBuffer)(x, y) = color;
		}
	}
}
