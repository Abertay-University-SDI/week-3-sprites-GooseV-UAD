#include "Level.h"
#include "Player.h"
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	playerObject.setInput(in); // may not be required but i'm scared

	

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	playerObject.playerInput(dt); // call player input in handle input otherwise no input is registered in level
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update(float dt)
{
	//calling pingPong inside the update for no actual reason and passing in Level's window parameters to avoid null pointer issues where two windows are called at once
	enemyObject.pingPong(dt, window->getSize().x, window->getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(playerObject);
	window->draw(enemyObject);
	endDraw();
}
