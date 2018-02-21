#include "Framerate.h"

#include <thread>

Framerate::Framerate() : Framerate(0) {}

Framerate::Framerate(uint16_t targetFramerate) {
	SetTargetFramerate(targetFramerate);
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

uint16_t Framerate::GetTargetFramerate() const {
	return _targetFramerate;
}

void Framerate::SetTargetFramerate(uint16_t targetFramerate) {
	_targetFramerate = targetFramerate;
	//? Are microseconds precise enough or should I use nanoseconds?
	if (targetFramerate > 0) {
		_maximumFrameTime = std::chrono::microseconds(1000000 / targetFramerate);
	} else {
		_maximumFrameTime = std::chrono::microseconds(0);
	}
	// This encourages the program to think that it needs to update the frame right after
	// construction or a reset time span.
	ManualReset();
}
