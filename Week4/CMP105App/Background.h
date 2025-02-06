#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include <iostream>
#include <string.h>


class Background : public GameObject {
public:
	Background();
	~Background();

	void fakeMovement(float playerX, float winX, float playerVelocity, float dt);

private:
	sf::Texture texture;
};