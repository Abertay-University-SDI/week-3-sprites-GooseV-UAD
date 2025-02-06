#include "Cursor.h"

Cursor::Cursor() {
	mouse.loadFromFile("gfx/clickbabytheredarrow.png");
	if (!mouse.loadFromFile("gfx/clickbabytheredarrow.png")) {
		std::cout << "Texture not located for object Cursor" << std::endl;
		mouse.loadFromFile("fallback/noTex.png");
	}
	this->setTexture(&mouse);
	this->setSize(sf::Vector2f(48,48));
	this->setPosition(0,0);
	

}

Cursor::~Cursor() {

}
void Cursor::setCursorPos(float mouseX, float mouseY) {
	this->setPosition(mouseX, mouseY);
}

void Cursor::clickCursor(bool clicked) {

	if (clicked == true) {
		mouse.loadFromFile("gfx/clickbabytheclosedarrow.png");
		if (!mouse.loadFromFile("gfx/clickbabytheclosedarrow.png")) {
			std::cout << "Texture not located for object Cursor1" << std::endl;
			mouse.loadFromFile("fallback/noTex.png");
		}
		this->setTexture(&mouse);
	}

	else {
		mouse.loadFromFile("gfx/clickbabytheredarrow.png");
		if (!mouse.loadFromFile("gfx/clickbabytheredarrow.png")) {
			std::cout << "Texture not located for object Cursor" << std::endl;
			mouse.loadFromFile("fallback/noTex.png");
		}
		this->setTexture(&mouse);
	}
}