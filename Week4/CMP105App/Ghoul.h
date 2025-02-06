#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include <iostream>
#include <string.h>
#include "Enemy.h"

class Ghoul : public Enemy {
public:
	Ghoul();
	~Ghoul();

	virtual void pingPong(float dt, int winX, int winY);

private:
	float velocityX{ 0 };
	float velocityY{ 0 };
	sf::Texture texture;
};