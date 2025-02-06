#include "Ghoul.h"

Ghoul::Ghoul() {
	texture.loadFromFile("gfx/kojima-shotgun.png");
	if (!texture.loadFromFile("gfx/kojima-shotgun.png")) {
		std::cout << "Texture not located for object Ghoul" << std::endl;
		texture.loadFromFile("fallback/noTex.png");
	}
	this->setTexture(&texture);
	this->setSize(sf::Vector2f(100, 100));
	this->setPosition(200, 450);
	velocityX = 200.0f;
	velocityY = -200.0f;
}

Ghoul::~Ghoul() {

}

void Ghoul::pingPong(float dt, int winX, int winY) {

	this->move(velocityX * dt, (velocityY * dt));

	if (this->getPosition().x < 0 || this->getPosition().x >= winX - this->getSize().x) {
		velocityX *= -1;

	}
	else if (this->getPosition().y < 0 || this->getPosition().y >= winY - this->getSize().y) {
		velocityY *= -1;
	}

}