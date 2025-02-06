#include "Player.h"


Player::Player() {
	texture.loadFromFile("gfx/MushroomTrans.png");
	if (!texture.loadFromFile("gfx/MushroomTrans.png")) {
		std::cout << "Texture not located for object Player" << std::endl;
		texture.loadFromFile("fallback/noTex.png");
	}
	this->setTexture(&texture); 
	this->setSize(sf::Vector2f(100, 100)); // def parameters
	this->setPosition(600, 100);
	this->setInput(input);
	velocity = 100.0f;
}

Player::~Player() {
}

void Player::playerInput(float dt, float winX, float winY)
{
	if (input->isKeyDown(sf::Keyboard::W)) {
		if (this->getPosition().y < 0){
			this->setPosition(this->getPosition().x, 0);
		}
		this->move(0,(velocity*dt)*-1);
	}
	else if (input->isKeyDown(sf::Keyboard::S)) {
		if (this->getPosition().y > (winY - this->getSize().y)) {
			this->setPosition(this->getPosition().x, (winY - this->getSize().y));
		}
		this->move(0, velocity * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::A)) {
		if (this->getPosition().x < 0) {
			this->setPosition(0, this->getPosition().y);
		}
		this->move((velocity * dt) * -1, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::D)) {
		if (this->getPosition().x > (winX - this->getSize().x)) {
			this->setPosition((winX - this->getSize().x), this->getPosition().y);
		}

		this->move(velocity * dt, 0);
	}
} 
// basic movement - this doesn't support all cardinal directions however as movement is replaced when called and not added onto, might fix later on saturday