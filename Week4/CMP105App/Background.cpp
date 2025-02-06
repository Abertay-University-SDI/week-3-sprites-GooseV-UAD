#include "Background.h"
#include "Player.h";

Background::Background() {
	texture.loadFromFile("gfx/Level1_1.png");
	if (!texture.loadFromFile("gfx/Level1_1.png")) {
		std::cout << "Texture not located for object Background" << std::endl;
		texture.loadFromFile("fallback/noTex.png");
	}
	this->setTexture(&texture);
	this->setSize(sf::Vector2f(10038, 675));
	this->setPosition(0, 0);
}

Background::~Background() {

}

void Background::fakeMovement(float playerX, float winX, float playerVelocity, float dt) {
	if (playerX <= 0 && this->getPosition().x > 0) {
		this->move(0.2 ,0);
		std::cout << this->getPosition().x << std::endl;
	}
	if (playerX > (winX - 100) && this->getPosition().x > (-8300)) {
		this->move(-0.2 , 0); // can't use deltatime here because values less than one round down to zero
		std::cout << this->getPosition().x << std::endl;
	}
}