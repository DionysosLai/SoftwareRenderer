#include <iostream>
#include "SDL.h"
#include "include/vector.h"
#include "include/displayManager.h"
#include "include/rasterizer.h"

int main(int argc, char *argv[]) {

	DisplayManager* dp = new DisplayManager();
	if (!dp->startUp()) {
		return 0;
	}

	int pixelCount = dp->SCREEN_WIDTH * dp->SCREEN_HEIGHT;
	Buffer<unsigned int>* pixels = new Buffer<Uint32>(dp->SCREEN_WIDTH, dp->SCREEN_HEIGHT, new unsigned int[pixelCount]);
	Rasterizer* rasterizer = new Rasterizer();

	int dap = 10;
	while (true)
	{
		Vector3f v1(0, 0, 0), v2(dp->SCREEN_WIDTH - dap, dp->SCREEN_HEIGHT, 0);
		rasterizer->drawLineDDA1(v1, v2, 100, pixels);
		dp->swapBuffers(pixels);
		
		SDL_Delay(1000);
		dap += 100;
	}

	return 0;
}