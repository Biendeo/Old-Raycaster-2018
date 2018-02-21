#include <iostream>
#include <SDL.h>
#include <string>

#include "Framerate.h"

static const size_t WIDTH = 640;
static const size_t HEIGHT = 480;

int main(int argc, char* argv[]) {
	//TODO: Add more properties to here if I need any.
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_GL_SetSwapInterval(1);

	SDL_Event e;

	// This is just for demo purposes.
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	bool exiting = false;

	// 60FPS is a reasonable expectation, but it should be flexible later on.
	Framerate fr(60);

	int frameCount = 0;

	while (!exiting) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
				exiting = true;
			}
		}

		fr.WaitAndUpdate();
		++frameCount;
		SDL_SetWindowTitle(window, std::to_string(frameCount).c_str());

		SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		r += 2;
		g += 3;
		b += 5;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}