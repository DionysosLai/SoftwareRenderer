#ifndef _RASTERIZER_H
#define _RASTERIZER_H

#include "vector.h"
#include "Buffer.h"
#include "SDL.h"

// ���������դ����������
class Rasterizer
{
public:
	Rasterizer();
	~Rasterizer();

	// ����ֱ�߻����㷨������y=kx+b��û�����κδ���
	void drawLineBase(Vector3f &vertex1, Vector3f &vertex2, const Uint32 &color, Buffer< Uint32> *pixelBuffer);

	// ����ֱ�߻����㷨������DDA�㷨
	void drawLineDDA(Vector3f &vertex1, Vector3f &vertex2, const Uint32 &color, Buffer< Uint32> *pixelBuffer);
	// DDA�㷨�Ż�
	void drawLineDDA1(Vector3f &vertex1, Vector3f &vertex2, const Uint32 &color, Buffer< Uint32> *pixelBuffer);
private:

};


#endif
