#ifndef _RASTERIZER_H
#define _RASTERIZER_H

#include "vector.h"
#include "Buffer.h"
#include "SDL.h"

// 用来处理光栅化具体内容
class Rasterizer
{
public:
	Rasterizer();
	~Rasterizer();

	// 基础直线绘制算法，采用y=kx+b，没有做任何处理
	void drawLineBase(Vector3f &vertex1, Vector3f &vertex2, const Uint32 &color, Buffer< Uint32> *pixelBuffer);

private:

};


#endif
