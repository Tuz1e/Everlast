#include "pch.h"
#include "Game.h"
#include "MathFunc.h"
#include "TextureContainer.h"

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
	TextureContainer *tempTextureCon = new TextureContainer();

	//myWorldManager.LoadContent(tempTextureCon, aWindow);
	myPlayer.LoadContent(tempTextureCon);
	myObjects.LoadContent(tempTextureCon);

	printf("\nLoaded Content.");
}

void Game::Update(float &aDeltaTime)
{
	myPlayer.Update(aDeltaTime);
	myObjects.Update(aDeltaTime);
}

void Game::Render(sf::RenderWindow &aWindow)
{
	//myWorldManager.Render(aWindow);
	myPlayer.Render(aWindow);
	myObjects.Render(aWindow);
}

void Game::LateRender(sf::RenderWindow & aWindow)
{
	//Render UI Elements
}