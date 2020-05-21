#ifndef _DISPLAY_MANAGER_H
#define _DISPLAY_MANAGER_H

#include <iostream>

#include "SDL.h"
#include "Buffer.h"

/*
*	������ʾ�������
*	�ڲ����ܣ���ʼ�� sdl
*/
// ����������ʾ
class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	const static int SCREEN_WIDTH = 1280; //640 1280
	const static int SCREEN_HEIGHT = 720; //480 720
	const static int SCREEN_PITCH = SCREEN_HEIGHT * sizeof(Uint32);
	constexpr static float SCREEN_ASPECT_RATIO = SCREEN_WIDTH / (float)SCREEN_HEIGHT;

	//Initializes SDL context and creates window according to above values
	bool startUp();
	void shutDown();

	//Swaps the pixel buffer with the window surface buffer and draws to screen
	void swapBuffers(Buffer<Uint32> *pixelBuffer);

private:
	
	// ��ʼ���ʹ�������
	bool startSDL();
	bool createWindow();
	bool createScreenSurface();

	//Pointers to the SDL window and surface
	SDL_Surface  *mSurface;
	SDL_Window   *mWindow;
};



#endif
