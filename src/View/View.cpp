#include "View.h"

#include <sstream>
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

	//TODO: Make this much more concise.
	bool forward = false;
	bool backward = false;
	bool strafeLeft = false;
	bool strafeRight = false;
	bool turnLeft = false;
	bool turnRight = false;

	while (!exiting) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
				exiting = true;
			} else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
					case SDLK_w:
					case SDLK_UP:
						forward = true;
						break;
					case SDLK_s:
					case SDLK_DOWN:
						backward = true;
						break;
					case SDLK_a:
						strafeLeft = true;
						break;
					case SDLK_d:
						strafeRight = true;
						break;
					case SDLK_LEFT:
						turnLeft = true;
						break;
					case SDLK_RIGHT:
						turnRight = true;
						break;
				}
			} else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
					case SDLK_w:
					case SDLK_UP:
						forward = false;
						break;
					case SDLK_s:
					case SDLK_DOWN:
						backward = false;
						break;
					case SDLK_a:
						strafeLeft = false;
						break;
					case SDLK_d:
						strafeRight = false;
						break;
					case SDLK_LEFT:
						turnLeft = false;
						break;
					case SDLK_RIGHT:
						turnRight = false;
						break;
				}
			}
		}

		//? If the program runs slower than the targeted framerate, this won't run at the right
		//? speed.
		_engine->RunLoop(1.0f / _framerate.GetTargetFramerate());

		if (forward) {
			_engine->GetPlayer().MoveForward(1.0f / _framerate.GetTargetFramerate());
		}
		if (backward) {
			_engine->GetPlayer().MoveBackward(1.0f / _framerate.GetTargetFramerate());
		}
		if (strafeLeft) {
			_engine->GetPlayer().StrafeLeft(1.0f / _framerate.GetTargetFramerate());
		}
		if (strafeRight) {
			_engine->GetPlayer().StrafeRight(1.0f / _framerate.GetTargetFramerate());
		}
		if (turnLeft) {
			_engine->GetPlayer().TurnLeft(1.0f / _framerate.GetTargetFramerate());
		}
		if (turnRight) {
			_engine->GetPlayer().TurnRight(1.0f / _framerate.GetTargetFramerate());
		}

		_framerate.WaitAndUpdate();
		++_frameCount;

		std::stringstream titleStream;
		titleStream << std::to_string(_frameCount) << " (" << _engine->GetPlayer().GetPosition().X() << ", " << _engine->GetPlayer().GetPosition().Y() << ", " << _engine->GetPlayer().GetPosition().Z() << ") r: " << _engine->GetPlayer().GetRotation();

		SDL_SetWindowTitle(_window, titleStream.str().c_str());

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
