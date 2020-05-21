#include "../include/displayManager.h"

DisplayManager::DisplayManager() {

}

DisplayManager::~DisplayManager() {

}

// 启动sdl，流程包括初始化和窗口创建
bool DisplayManager::startUp() {
	if (!startSDL()) {
		return false;
	}

	if (!createWindow()) {
		return false;
	}
	if (!createScreenSurface()) {
		return false;
	}
	return true;
}

// 关闭sdl
// Closes down sdl and destroys window.
// SDL surface is also destroyed in the call to destroy window
void DisplayManager::shutDown() {
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
	SDL_Quit();
}

// 界面刷新
void DisplayManager::swapBuffers(Buffer<Uint32> *pixels) {
	//Allows surface editing 
	SDL_LockSurface(mSurface);

	//Copy pixels buffer resuls to screen surface
	memcpy(mSurface->pixels, pixels->buffer, pixels->mHeight*pixels->mPitch);
	SDL_UnlockSurface(mSurface);

	//Apply surface changes to window
	SDL_UpdateWindowSurface(mWindow);
}

//Entry point to SDL
bool DisplayManager::startSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Failed to initialize SDL. Error: %s\n", SDL_GetError());
		return  false;
	}
	return true;
}

//Inits window with the display values crated at compile time
bool DisplayManager::createWindow() {
	mWindow = SDL_CreateWindow("SoftwareRenderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (mWindow == nullptr) {
		printf("Could not create window. Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

//Gets the screen surface
bool DisplayManager::createScreenSurface() {
	mSurface = SDL_GetWindowSurface(mWindow);
	if (mSurface == NULL) {
		printf("Could not create window surface. Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}