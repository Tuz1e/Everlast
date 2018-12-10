#include "pch.h"
#include "Game.h"
#include "MathFunc.h"

class TextureContainer;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	printf("\nInitialized Game.");
}

void Game::LoadContent(sf::RenderWindow &aWindow)
{
	TextureContainer tempTextureCon;

	myPlayer.LoadContent(tempTextureCon);

	printf("\nLoaded Content.");
}

void Game::Update(float &aDeltaTime)
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