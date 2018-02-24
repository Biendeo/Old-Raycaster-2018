#include "View.h"

#include <cmath>
#include <sstream>
#include <string>

#include "Input.h"

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
	_framerate = Framerate(144);
	_frameCount = 0;

	// Key bindings with SDL.
	Input::BindKey(SDLK_w, Input::InputAction::MoveForward);
	Input::BindKey(SDLK_UP, Input::InputAction::MoveForward);
	Input::BindKey(SDLK_s, Input::InputAction::MoveBackward);
	Input::BindKey(SDLK_DOWN, Input::InputAction::MoveBackward);
	Input::BindKey(SDLK_a, Input::InputAction::StrafeLeft);
	Input::BindKey(SDLK_d, Input::InputAction::StrafeRight);
	Input::BindKey(SDLK_LEFT, Input::InputAction::TurnLeft);
	Input::BindKey(SDLK_RIGHT, Input::InputAction::TurnRight);
}

void View::Loop() {
	SDL_Event e;

	// This is just for demo purposes.
	bool exiting = false;

	_framerate.ManualReset();

	_engine->Start();

	while (!exiting) {
		Input::UpdateInputs();
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
				exiting = true;
			} else if (e.type == SDL_KEYDOWN) {
				Input::PressKeyDown(e.key.keysym.sym);
			} else if (e.type == SDL_KEYUP) {
				Input::PressKeyUp(e.key.keysym.sym);
			}
		}

		//? If the program runs slower than the targeted framerate, this won't run at the right
		//? speed.
		_engine->RunLoop(1.0f / _framerate.GetTargetFramerate());

		if (Input::IsAction(Input::InputAction::MoveForward)) {
			_engine->GetPlayer().MoveForward(1.0f / _framerate.GetTargetFramerate());
		}
		if (Input::IsAction(Input::InputAction::MoveBackward)) {
			_engine->GetPlayer().MoveBackward(1.0f / _framerate.GetTargetFramerate());
		}
		if (Input::IsAction(Input::InputAction::StrafeLeft)) {
			_engine->GetPlayer().StrafeLeft(1.0f / _framerate.GetTargetFramerate());
		}
		if (Input::IsAction(Input::InputAction::StrafeRight)) {
			_engine->GetPlayer().StrafeRight(1.0f / _framerate.GetTargetFramerate());
		}
		if (Input::IsAction(Input::InputAction::TurnLeft)) {
			_engine->GetPlayer().TurnLeft(1.0f / _framerate.GetTargetFramerate());
		}
		if (Input::IsAction(Input::InputAction::TurnRight)) {
			_engine->GetPlayer().TurnRight(1.0f / _framerate.GetTargetFramerate());
		}

		RenderScene();

		_framerate.WaitAndUpdate();
		++_frameCount;

		std::stringstream titleStream;
		titleStream << std::to_string(_frameCount) << " (" << _engine->GetPlayer().GetPosition().X() << ", " << _engine->GetPlayer().GetPosition().Y() << ", " << _engine->GetPlayer().GetPosition().Z() << ") r: " << _engine->GetPlayer().GetRotation();

		SDL_SetWindowTitle(_window, titleStream.str().c_str());
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

void View::RenderScene() {
	// We'll clear the buffer with the sky color first.
	SDL_SetRenderDrawColor(_renderer, _engine->GetSkyColor().R(), _engine->GetSkyColor().G(), _engine->GetSkyColor().B(), SDL_ALPHA_OPAQUE);
	SDL_RenderClear(_renderer);

	// Then draw the floor. Since I'm not looking up or down, the floor will just be half the
	// screen.
	SDL_SetRenderDrawColor(_renderer, _engine->GetFloorColor().R(), _engine->GetFloorColor().G(), _engine->GetFloorColor().B(), SDL_ALPHA_OPAQUE);
	SDL_Rect floorRectangle;
	floorRectangle.x = 0;
	floorRectangle.y = HEIGHT / 2;
	floorRectangle.w = WIDTH;
	floorRectangle.h = HEIGHT / 2;
	SDL_RenderFillRect(_renderer, &floorRectangle);

	// Now to draw each wall, for each horizontal pixel, find the wall that would be the closest
	// and draw that.
	//TODO: Clearly this isn't efficient, it's just a starting point.
	static const float DEG_TO_RAD = static_cast<float>(M_PI) / 180.0f;
	static const float RAD_TO_DEG = 180.0f / static_cast<float>(M_PI);
	static const float fov = 50.0f;
	Vector2 playerPosition = Vector2(_engine->GetPlayer().GetPosition().X(), _engine->GetPlayer().GetPosition().Z());
	for (int x = 0; x < WIDTH; ++x) {
		float currentDirection = _engine->GetPlayer().GetRotation() + (WIDTH / 2.0f - x) / WIDTH * fov;
		Wall* closestWall = nullptr;
		float closestDistance = 10000000.0f;
		Vector2 unitInFront = playerPosition + Vector2(cosf(currentDirection * DEG_TO_RAD), sinf(currentDirection * DEG_TO_RAD));
		for (auto& wall : _engine->GetMap().GetWalls()) {
			try {
				Vector2 pointOfIntersection = Intersection(wall.GetLeftPoint(), wall.GetRightPoint(), playerPosition, unitInFront);

				// Just to determine whether this point is in front of the camera or not, we look
				// for a positive value to this parametric form.
				if (((pointOfIntersection - playerPosition) / Vector2(cosf(currentDirection * DEG_TO_RAD), sinf(currentDirection * DEG_TO_RAD))).X() > 0.0f && (pointOfIntersection - playerPosition).Magnitude() <= closestDistance) {
					// And on top of that, check that the point of intersection is between the
					// wall's points.
					if (((pointOfIntersection - wall.GetLeftPoint()) / (wall.GetRightPoint() - wall.GetLeftPoint())).X() >= 0.0f && ((pointOfIntersection - wall.GetLeftPoint()) / (wall.GetRightPoint() - wall.GetLeftPoint())).X() <= 1.0f) {
						closestWall = &wall;
						closestDistance = (pointOfIntersection - playerPosition).Magnitude();
					}
				}
			} catch (std::runtime_error& e) {
				// I'm going to ignore the exceptions here.
				(void)e;
			}
		}

		if (closestWall != nullptr) {
			static const float vfov = fov / WIDTH * HEIGHT;
			// I'm assuming that the walls are one unit high.
			// The denominator here is for some basic perspective correction, although it isn't
			// perfect.
			float heightAngle = atan2f(1.0f, closestDistance) * RAD_TO_DEG / (cosf((currentDirection - _engine->GetPlayer().GetRotation()) * DEG_TO_RAD));
			//TODO: This isn't exact but it does the job.
			int pixelHeight = HEIGHT;
			if (heightAngle < vfov) {
				pixelHeight = heightAngle / vfov * HEIGHT;
			}
			SDL_SetRenderDrawColor(_renderer, closestWall->GetColor().R(), closestWall->GetColor().G(), closestWall->GetColor().B(), closestWall->GetColor().A());
			//? Is a rectangle too slow?
			SDL_Rect wallRectangle;
			wallRectangle.x = x;
			wallRectangle.y = (HEIGHT - pixelHeight) / 2;
			wallRectangle.w = 1;
			wallRectangle.h = pixelHeight;
			SDL_RenderFillRect(_renderer, &wallRectangle);
		}
	}

	SDL_RenderPresent(_renderer);
}

Vector2 View::Intersection(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4) {
	// If either p1 and p2 or p3 and p4 are equal, then a point was defined and not
	// a line, so we throw here.
	if (p1.X() == p2.X() && p1.Y() == p2.Y() || p3.X() == p4.X() && p3.Y() == p4.Y()) {
		throw std::runtime_error("A line was defined with two equal points, and cannot be determined.");
	}

	// Also detect if the lines are parallel and don't intersect.
	if (((p1.X() - p2.X()) * (p3.Y() - p4.Y())) - ((p1.Y() - p2.Y()) * (p3.X() - p4.X())) == 0.0f) {
		throw std::runtime_error("Two lines did not intersect.");
	}

	// This is a long formula but it should work.
	return Vector2(((p1.X() * p2.Y() - p1.Y() * p2.X()) * (p3.X() - p4.X()) - (p1.X() - p2.X()) * (p3.X() * p4.Y() - p3.Y() * p4.X())) / (((p1.X() - p2.X()) * (p3.Y() - p4.Y())) - (p1.Y() - p2.Y()) * (p3.X() - p4.X())), ((p1.X() * p2.Y() - p1.Y() * p2.X()) * (p3.Y() - p4.Y()) - (p1.Y() - p2.Y()) * (p3.X() * p4.Y() - p3.Y() * p4.X())) / (((p1.X() - p2.X()) * (p3.Y() - p4.Y())) - (p1.Y() - p2.Y()) * (p3.X() - p4.X())));
}
