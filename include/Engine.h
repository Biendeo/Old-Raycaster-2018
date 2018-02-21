#pragma once

#include <cstdint>

#include "Framerate.h"

class Engine {
	public:
	/**
	 * Constructs an engine object.
	 */
	Engine();

	/**
	 * Begins the execution of the program.
	 */
	void Start();

	/**
	 * Runs a step in the program's execution.
	 * @param deltaTime The number of seconds since the last frame.
	 */
	void RunLoop(float deltaTime);

	/**
	 * Cleans up loose variables of the program.
	 */
	void Finalise();

	private:
};


