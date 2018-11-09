#include "pch.h"
#include "Game.h"
#include "MathFunc.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
}

void Game::LoadContent()
{
	myPlayer.LoadContent();
}

void Game::Update(const float &aDeltaTime)
{
	myPlayer.Update(aDeltaTime);
}

void Game::Render(sf::RenderWindow &aWindow)
{
	myPlayer.Render(aWindow);
}

void Game::LateRender(sf::RenderWindow & aWindow)
{
	//Render UI Elements
}