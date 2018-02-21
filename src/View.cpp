#include "View.h"

#include <string>

View::View(Engine* engine) {
	//TODO: Nullcheck the engine.
	_engine = engine;
	// This is for safety checks.
	_window = nullptr;
	_renderer = nullptr;
}

View::~View() {
	delete _engine;
}

void View::InitialiseSDL() {
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
	_framerate = Framerate(60);
	_frameCount = 0;
}

void View::Loop() {
	SDL_Event e;

	// This is just for demo purposes.
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	bool exiting = false;

	_framerate.ManualReset();

	_engine->Start();

	while (!exiting) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
				exiting = true;
			}
		}

		//? If the program runs slower than the targeted framerate, this won't run at the right
		//? speed.
		_engine->RunLoop(1.0f / _framerate.GetTargetFramerate());

		_framerate.WaitAndUpdate();
		++_frameCount;
		SDL_SetWindowTitle(_window, std::to_string(_frameCount).c_str());

		SDL_SetRenderDrawColor(_renderer, r, g, b, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(_renderer);
		SDL_RenderPresent(_renderer);
		r += 2;
		g += 3;
		b += 5;
	}

	_engine->Finalise();
}

void View::DisposeSDL() {
	if (_renderer != nullptr) {
		SDL_DestroyRenderer(_renderer);
	}

	if (_window != nullptr) {
		SDL_DestroyWindow(_window);
	}
	SDL_Quit();
}
