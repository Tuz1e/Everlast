#include "pch.h"
#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

Key Input::GetKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		return UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		return DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		return LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return RIGHT;
	}

	return NONE;
}