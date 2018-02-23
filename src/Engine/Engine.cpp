#include "Engine.h"

Engine::Engine() = default;

void Engine::Start() {
	//TODO: This just demonstrates some walls.
	GetMap().AddWall(Wall(Vector2(-4.0f, -4.4f), Vector2(-2.0f, -5.0f), Color(1.0f, 1.0f, 1.0f)));
	GetMap().AddWall(Wall(Vector2(2.0f, -4.4f), Vector2(3.0f, 0.0f), Color(0.0f, 1.0f, 1.0f)));
	_floorColor = Color(0.2f, 0.3f, 0.5f);
	_skyColor = Color(0.4f, 0.5f, 0.8f);
}

void Engine::RunLoop(float deltaTime) {

}

Player& Engine::GetPlayer() {
	return _player;
}

Map& Engine::GetMap() {
	return _map;
}

void Engine::Finalise() {

}
