#include "Player.h"

#include <cmath>

static const float DEG_TO_RAD = static_cast<float>(M_PI) / 180.0f;
static const float RAD_TO_DEG = 180.0f / static_cast<float>(M_PI);

Player::Player() : _position(), _rotation(0.0f) {}

Vector3 Player::GetPosition() const {
	return _position;
}

float Player::GetRotation() const {
	return _rotation;
}

void Player::MoveForward(float deltaTime) {
	_position += Vector3(cosf(_rotation * DEG_TO_RAD), 0.0f, sinf(_rotation * DEG_TO_RAD)) * MOVEMENT_SPEED * deltaTime;
}

void Player::MoveBackward(float deltaTime) {
	MoveForward(-deltaTime);
}

void Player::StrafeLeft(float deltaTime) {
	_position += Vector3(-sinf(_rotation * DEG_TO_RAD), 0.0f, cosf(_rotation * DEG_TO_RAD)) * MOVEMENT_SPEED * deltaTime;
}

void Player::StrafeRight(float deltaTime) {
	StrafeLeft(-deltaTime);
}

void Player::TurnLeft(float deltaTime) {
	_rotation += ROTATION_SPEED * deltaTime;
}

void Player::TurnRight(float deltaTime) {
	TurnLeft(-deltaTime);
}
