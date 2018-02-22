#pragma once

#include "Vector3.h"

class Player {
	public:
	Player();

	/**
	 * Retuns the current position of the player.
	 * @return
	 */
	Vector3 GetPosition() const;

	/**
	 * Returns the current rotation of the player.
	 * @return
	 */
	float GetRotation() const;

	/**
	 * Moves the player forward by the given time amount.
	 * @param deltaTime
	 */
	void MoveForward(float deltaTime);

	/**
	 * Moves the player backward by the given time amount.
	 * @param deltaTime
	 */
	void MoveBackward(float deltaTime);

	/**
	 * Strafes the player left by the given time amount.
	 * @param deltaTime
	 */
	void StrafeLeft(float deltaTime);

	/**
	 * Strafes the player right by the given time amount.
	 * @param deltaTime
	 */
	void StrafeRight(float deltaTime);

	/**
	 * Turns the player left by the given time amount.
	 * @param deltaTime
	 */
	void TurnLeft(float deltaTime);

	/**
	 * Turns the player right by the given time amount.
	 * @param deltaTime
	 */
	void TurnRight(float deltaTime);

	private:
	static constexpr float MOVEMENT_SPEED = 3.0f;
	static constexpr float ROTATION_SPEED = 180.0f;

	Vector3 _position;
	// For the moment, I only want to look left and right. Up and down will come later on.
	// The rotation is in Cartesian space (so 0 degrees is easterly, 90 is north, etc.).
	float _rotation;
};


