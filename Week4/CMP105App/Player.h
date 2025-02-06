#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include <iostream>
#include <string.h>


class Player : public GameObject {
	public:
		Player();
		~Player();

		void playerInput(float dt, float winX, float winY);

	private:
		sf::Texture texture;
		float velocity{ 0 };

};