#include "Level.h"
#include "Player.h"
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	playerObject.setInput(in); // may not be required but i'm scared
	window->setMouseCursorVisible(false);
	

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	playerObject.playerInput(dt, window->getSize().x, window->getSize().y); // call player input in handle input otherwise no input is registered in level
	theAccursedOne.setCursorPos(input->getMouseX(), input->getMouseY());
	theAccursedOne.clickCursor(input->isLeftMouseDown());
	
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
	ghoulObject.pingPong(dt, window->getSize().x, window->getSize().y);

	backObject.fakeMovement(playerObject.getPosition().x, window->getSize().x, 1.0f, dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(backObject);
	window->draw(playerObject);
	window->draw(enemyObject);
	window->draw(ghoulObject);
	window->draw(theAccursedOne);
	
	endDraw();
}
