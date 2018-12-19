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
	//PostNord::Initialize();

	myGState = GameState::GAME;
	myWM.Initialize();

	printf("\nInitialized Game.");
}

void Game::LoadContent(sf::RenderWindow &aWindow)
{
	TextureContainer tempTextureCon;
	myWM.LoadContent(tempTextureCon, aWindow);
	printf("\nLoaded Game Content.");
}

void Game::Update(float &aDeltaTime)
{
	switch (myGState)
	{
	case GameState::MENU:
		//TODO: Insert menu update sequence
		break;
	case GameState::GAME:
		myWM.Update(aDeltaTime);
		//TODO: Insert ability to pause
		break;
	case GameState::PAUSE:
		//TODO: When pausing
		break;
	}

	//myPlayer->Update(aDeltaTime);
	//myEM.Update(aDeltaTime, myPlayer->GetPosition());

	//myCM.Update(myPlayer, myEM);
	//myObjM.Update(aDeltaTime, myPlayer->GetHitbox(), myPlayer->GetVelocity(), myPlayer->GetPickupFlag());
}

void Game::Render(sf::RenderWindow &aWindow)
{
	switch (myGState)
	{
	case GameState::MENU:
		//TODO: Insert menu render sequence
		break;
	case GameState::GAME:
		myWM.Render(aWindow);
		break;
	case GameState::PAUSE:
		//TODO: Insert pause sequence
		break;
	}
}

void Game::LateRender(sf::RenderWindow & aWindow)
{
	//Render UI Elements
}