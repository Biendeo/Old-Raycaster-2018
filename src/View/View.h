#pragma once

#include <SDL.h>

#include "Engine.h"
#include "Framerate.h"
#include "Vector2.h"

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

	Framerate _framerate;

	/**
	 * Renders the scene and displays it to the renderer.
	 */
	void RenderScene();

	/**
	 * Computes the point where two lines intersect. If the two lines are parallel, then a
	 * runtime exception will be thrown.
	 * //TODO: This would be better in a separate math library. Also test this a lot!
	 * @param p1
	 * @param p2
	 * @param p3
	 * @param p4
	 * @return
	 */
	Vector2 Intersection(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4);
};


