#include "Enemy.h"

Enemy::Enemy() {
	texture.loadFromFile("gfx/Goomba.png");
	if (!texture.loadFromFile("gfx/Goomba.png")) {
		std::cout << "Texture not located for object Enemy" << std::endl;
		texture.loadFromFile("fallback/noTex.png");
	}
	this->setTexture(&texture);
	this->setSize(sf::Vector2f(100, 100));
	this->setPosition(200, 200);
	this->setInput(input);
	velocityX = 200.0f;
	velocityY = 200.0f;
}

Enemy::~Enemy() {

}

void Enemy::pingPong(float dt, int winX, int winY) {

	this->move(velocityX * dt, velocityY * dt);

	if (this->getPosition().x < 0 || this->getPosition().x >= winX - this->getSize().x){
		velocityX *= -1;

	}
	else if (this->getPosition().y < 0 || this->getPosition().y >= winY - this->getSize().y) {
		velocityY *= -1;
	}
}

//improved bouncing and if you're seeing this after what i did in week 2, yes there's now a y direction supported because somehow i forgot
// to put that in there but it exists now.
// no random direction because i don't want to