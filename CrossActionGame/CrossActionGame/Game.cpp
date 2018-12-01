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
	//mySprite.setTexture(*tempTextureCon.GetTexture(TILE_00));
	//mySprite.setPosition(0, 0);
	//mySprite.setScale(3.0f, 3.0f);

	//mySprite2.setTexture(*tempTextureCon.GetTexture(TILE_00));
	//mySprite2.setScale(3.0f, 3.0f);
	//mySprite2.setPosition(mySprite.getTextureRect().width * 3.0f, 0);

	//myWorldManager.LoadContent(tempTextureCon, aWindow);
	myPlayer.LoadContent(tempTextureCon);

	printf("\nLoaded Content.");
}

void Game::Update(float &aDeltaTime)
{
	myPlayer.Update(aDeltaTime);
}

void Game::Render(sf::RenderWindow &aWindow)
{
	aWindow.draw(mySprite);
	aWindow.draw(mySprite2);
	//myWorldManager.Render(aWindow);
	myPlayer.Render(aWindow);
}

void Game::LateRender(sf::RenderWindow & aWindow)
{
	//Render UI Elements
}