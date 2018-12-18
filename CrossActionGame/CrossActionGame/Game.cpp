#include "pch.h"
#include "Game.h"
#include "PostNord.h"

class TextureContainer;

Game::Game()
{
}

Game::~Game()
{
	PtrDelete(myPlayer);
}

void Game::Initialize()
{
	PostNord::Initialize();

	myPlayer = new Player();
	myPlayer->Initialize();
	myEM.Initialize();
	myObjM.Initialize();
	printf("\nInitialized Game.");
}

void Game::LoadContent(sf::RenderWindow &aWindow)
{
	TextureContainer tempTextureCon;

	myPlayer->LoadContent(tempTextureCon);
	myEM.LoadContent(tempTextureCon);
	myObjM.LoadContent(tempTextureCon);
	printf("\nLoaded Content.");
}

void Game::Update(float &aDeltaTime)
{
	myPlayer->Update(aDeltaTime);
	myEM.Update(aDeltaTime, myPlayer->GetPosition());

	myCM.Update(myPlayer, myEM);
	myObjM.Update(aDeltaTime, myPlayer->GetHitbox(), myPlayer->GetVelocity(), myPlayer->GetPickupFlag());
}

void Game::Render(sf::RenderWindow &aWindow)
{
	myEM.Render(aWindow);
	myPlayer->Render(aWindow);
	myObjM.Render(aWindow);
}

void Game::LateRender(sf::RenderWindow & aWindow)
{
	//Render UI Elements
}