#pragma once

#include <SDL.h>

namespace Input {
	/**
	 * The actions that the user can perform in the game.
	 */
	enum class InputAction {
		MoveForward,
		MoveBackward,
		StrafeLeft,
		StrafeRight,
		TurnLeft,
		TurnRight
	};

	/**
	 * Checks whether a specific key was pressed down this current frame.
	 * @param key
	 * @return
	 */
	bool IsKeyDown(SDL_Keycode key);

	/**
	 * Checks whether a specific key was released this current frame.
	 * @param key
	 * @return
	 */
	bool IsKeyUp(SDL_Keycode key);

	/**
	 * Checks whether a specific key is currently down.
	 * @param key
	 * @return
	 */
	bool IsKey(SDL_Keycode key);

	/**
	 * Checks whether a specific action was pressed down this current frame.
	 * @param action
	 * @return
	 */
	bool IsActionDown(InputAction action);

	/**
	 * Checks whether a specific action was released this current frame.
	 * @param action
	 * @return
	 */
	bool IsActionUp(InputAction action);

	/**
	 * Checks whether a specific action is currently down.
	 * @param action
	 * @return
	 */
	bool IsAction(InputAction action);

	/**
	 * Binds an action to a key. This means that calls to IsAction() etc. will be true if IsKey()
	 * is also true for any bound key.
	 * @param key
	 * @param action
	 */
	void BindKey(SDL_Keycode key, InputAction action);

	/**
	 * Unbinds an action from a key. This means that calls to IsAction() etc. will not be true
	 * if IsKey() is only true for that key.
	 * @param key
	 * @param action
	 */
	void UnbindKey(SDL_Keycode key, InputAction action);

	/**
	 * Unbinds all actions for a specific key. No IsAction() will be true if IsKey() is true only
	 * for this key.
	 * @param key
	 */
	void UnbindAllFromKey(SDL_Keycode key);

	/**
	 * Unbinds all keys for a specific action. No IsAction() will be true for this action.
	 * @param action
	 */
	void UnbindAllFromAction(InputAction action);

	/**
	 * Indicates that a specific SDL key has been pressed this frame.
	 * @param key
	 */
	void PressKeyDown(SDL_Keycode key);

	/**
	 * Indicates that a specific SDL key has been released this frame.
	 * @param key
	 */
	void PressKeyUp(SDL_Keycode key);

	/**
	 * Indicates that the frame is finished. Should be called once before any input is handled this
	 * frame.
	 */
	void UpdateInputs();

	//TODO: Add more involving other forms of input.
};

