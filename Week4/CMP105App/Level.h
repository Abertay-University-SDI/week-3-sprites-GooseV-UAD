#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Player.h"
#include "Enemy.h"
#include "Ghoul.h"
#include "Cursor.h"
#include "Background.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>


class Level : BaseLevel {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

private:
	// Level objects
	Cursor theAccursedOne;
	Background backObject;
	Player playerObject;
	Enemy enemyObject;
	Ghoul ghoulObject; // Ghoul is a child of Enemy
	sf::Texture texture;

};