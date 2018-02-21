#pragma once

#include <SDL.h>

#include "Engine.h"
#include "Framerate.h"

class View {
	public:
	/**
	 * Creates a new view object.
	 * @param engine
	 */
	View(Engine* engine);

	/**
	 * Disposes the view object.
	 */
	~View();

	/**
	 * Initialises SDL variables and displays the window.
	 */
	void InitialiseSDL();

	/**
	 * Runs the main execution of the window, and only exits once the engine is finished.
	 */
	void Loop();

	/**
	 * Disposes SDL variables and destroys the window.
	 */
	void DisposeSDL();

	private:
	static const Uint16 WIDTH = 640;
	static const Uint16 HEIGHT = 480;

	uint16_t _frameCount;

	Engine* _engine;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SDL_Surface* _frontBuffer;
	SDL_Surface* _backBuffer;

	Framerate _framerate;
};


