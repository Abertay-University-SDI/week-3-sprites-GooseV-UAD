#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <iostream>
#include <string.h>

class Cursor : public GameObject {
public:
	Cursor();
	~Cursor();

	void setCursorPos(float mouseX, float mouseY);

	void clickCursor(bool clicked);

private:
	sf::Texture mouse;
};