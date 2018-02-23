#include "Input.h"

#include <map>

namespace Input {
	static std::map<SDL_Keycode, bool> previousKeyDown;
	static std::map<SDL_Keycode, bool> currentKeyDown;
	static std::map<SDL_Keycode, bool> futureKeyDown;
	static std::multimap<InputAction, SDL_Keycode> keyBindings;

	bool IsKeyDown(SDL_Keycode key) {
		return currentKeyDown[key] && !previousKeyDown[key];
	}

	bool IsKeyUp(SDL_Keycode key) {
		return !currentKeyDown[key] && previousKeyDown[key];
	}

	bool IsKey(SDL_Keycode key) {
		return currentKeyDown[key];
	}

	bool IsActionDown(InputAction action) {
		bool downPrevious = false;
		bool downCurrent = false;
		for (auto it = keyBindings.equal_range(action).first; it != keyBindings.equal_range(action).second; ++it) {
			if (previousKeyDown[(*it).second]) {
				downPrevious = true;
			}
			if (currentKeyDown[(*it).second]) {
				downCurrent = true;
			}
		}
		return downCurrent && !downPrevious;
	}

	bool IsActionUp(InputAction action) {
		bool downPrevious = false;
		bool downCurrent = false;
		for (auto it = keyBindings.equal_range(action).first; it != keyBindings.equal_range(action).second; ++it) {
			if (previousKeyDown[(*it).second]) {
				downPrevious = true;
			}
			if (currentKeyDown[(*it).second]) {
				downCurrent = true;
			}
		}
		return !downCurrent && downPrevious;
	}

	bool IsAction(InputAction action) {
		bool downCurrent = false;
		for (auto it = keyBindings.equal_range(action).first; it != keyBindings.equal_range(action).second; ++it) {
			if (currentKeyDown[(*it).second]) {
				// This can probably be a quick exit.
				downCurrent = true;
			}
		}
		return downCurrent;
	}

	void BindKey(SDL_Keycode key, InputAction action) {
		keyBindings.insert(std::make_pair(action, key));
	}

	void UnbindKey(SDL_Keycode key, InputAction action) {
		//TODO: Maybe return true/false here?
		for (auto it = keyBindings.equal_range(action).first; it != keyBindings.equal_range(action).second; ++it) {
			if ((*it).second == key) {
				keyBindings.erase(it);
				return;
			}
		}
	}

	void UnbindAllFromKey(SDL_Keycode key) {
		for (auto it = keyBindings.begin(); it != keyBindings.end(); ) {
			if ((*it).second == key) {
				it = keyBindings.erase(it);
			} else {
				++it;
			}
		}
	}

	void UnbindAllFromAction(InputAction action) {
		keyBindings.erase(action);
	}

	void PressKeyDown(SDL_Keycode key) {
		futureKeyDown[key] = true;
	}

	void PressKeyUp(SDL_Keycode key) {
		futureKeyDown[key] = false;
	}

	void UpdateInputs() {
		// Is this too slow? I used to always use arrays, but maybe structures might be slower.
		previousKeyDown = currentKeyDown;
		currentKeyDown = futureKeyDown;
		// Usually I reset the future state, but considering I'm only handling changes in state, it
		// may be useful to keep the future state as it is.
		//futureKeyDown = std::map<SDL_Keycode, bool>();
	}
}