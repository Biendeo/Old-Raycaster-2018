#pragma once

#include <cstdint>

#include "Framerate.h"
#include "Player.h"

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
	 * //TODO: I might need to just remove this if the view is handling the time step.
	 * @param deltaTime The number of seconds since the last frame.
	 */
	void RunLoop(float deltaTime);

	/**
	 * Returns the current player object.
	 * @return
	 */
	Player& GetPlayer();

	/**
	 * Cleans up loose variables of the program.
	 */
	void Finalise();

	private:
	Player _player;
};


