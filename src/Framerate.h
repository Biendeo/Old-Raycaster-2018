#pragma once

#include <chrono>
#include <cstdint>

class Framerate {
	public:
	/**
	 * Default constructs a framerate object without any targeted frames per second. This'll
	 * automatically skip any waits.
	 */
	Framerate();

	/**
	 * Constructs a new framerate object with the targeted frames per second.
	 * @param targetFramerate
	 */
	Framerate(uint16_t targetFramerate);

	/**
	 * Resets the framerate timer and forces it to update immediately.
	 */
	void ManualReset();

	/**
	 * Sleeps the current thread until the timer is finished.
	 */
	void WaitForUpdate();

	/**
	 * Sets the last update at the current time.
	 */
	void Update();

	/**
	 * Sleeps until the timer is finished, and then sets it at the current time point.
	 */
	void WaitAndUpdate();

	/**
	 * Gets the targetted frames per second.
	 * @return
	 */
	uint16_t GetTargetFramerate() const;

	/**
	 * Sets the targetted frames per second and resets the counter.
	 * @param _targetFramerate
	 */
	void SetTargetFramerate(uint16_t targetFramerate);

	private:
	std::chrono::system_clock::time_point _lastUpdate;
	std::chrono::duration<long long, std::micro> _maximumFrameTime;

	uint16_t _targetFramerate;
};


