#include "Player.h"


Player::Player() {
	texture.loadFromFile("gfx/MushroomTrans.png");
	if (!texture.loadFromFile("gfx/MushroomTrans.png")) {
		std::cout << "texture not found \n"; // ideally i would have a fallback texture but no time
	}
	this->setTexture(&texture); 
	this->setSize(sf::Vector2f(100, 100)); // def parameters
	this->setPosition(100, 100);
	this->setInput(input);
	velocity = 100.0f;
}

Player::~Player() {
}

void Player::playerInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W)) {
		
		this->move(0,(velocity*dt)*-1);
	}
	else if (input->isKeyDown(sf::Keyboard::S)) {
		
		this->move(0, velocity * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::A)) {

		this->move((velocity * dt) * -1, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::D)) {

		this->move(velocity * dt, 0);
	}
} 
// basic movement - this doesn't support all cardinal directions however as movement is replaced when called and not added onto, might fix later on saturday