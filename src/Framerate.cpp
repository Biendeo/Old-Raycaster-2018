#include "Framerate.h"

#include <thread>

Framerate::Framerate(uint16_t targetFramerate) {
	_targetFramerate = targetFramerate;
	//? Are microseconds precise enough or should I use nanoseconds?
	_maximumFrameTime = std::chrono::microseconds(1000000 / targetFramerate);
	// This encourages the program to think that it needs to update the frame right after construction.
	ManualReset();
}

void Framerate::ManualReset() {
	_lastUpdate = std::chrono::system_clock::now() - _maximumFrameTime;
}

void Framerate::WaitForUpdate() {
	std::this_thread::sleep_until(_lastUpdate + _maximumFrameTime);
}

void Framerate::Update() {
	_lastUpdate = std::chrono::system_clock::now();
}

void Framerate::WaitAndUpdate() {
	WaitForUpdate();
	Update();
}
