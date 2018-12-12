#include "pch.h"
#include "Game.h"

class TextureContainer;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	myPlayer.Initialize();
	mySkW.Initialize();
	printf("\nInitialized Game.");
}

void Game::LoadContent(sf::RenderWindow &aWindow)
{
	TextureContainer tempTextureCon;

	myPlayer.LoadContent(tempTextureCon);
	mySkW.LoadContent(tempTextureCon);
	printf("\nLoaded Content.");
}

void Game::Update(float &aDeltaTime)
{
	myPlayer.Update(aDeltaTime);
	mySkW.Update(aDeltaTime, myPlayer.GetPosition());
}

void Game::Render(sf::RenderWindow &aWindow)
{
	mySkW.Render(aWindow);
	myPlayer.Render(aWindow);
}

void Game::LateRender(sf::RenderWindow & aWindow)
{
	//Render UI Elements
}