#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include <iostream>
#include <string.h>


class Enemy : public GameObject {
	public:
		Enemy();
		~Enemy();

		void pingPong(float dt, int winX, int winY);

	private:
		float velocityX{ 0 };
		float velocityY{ 0 };
		sf::Texture texture;

};