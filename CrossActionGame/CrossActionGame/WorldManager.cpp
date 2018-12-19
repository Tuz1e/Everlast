#include "pch.h"
#include "WorldManager.h"

WorldManager::WorldManager()
{
}

WorldManager::~WorldManager()
{
	PtrDelete(myLocale);
	PtrDelete(myPlayer);
}

void WorldManager::Initialize()
{
	myLocale = new Locale();
	*myLocale = Locale::START;

	myPlayer = new Player();
	myPlayer->Initialize();
	myPlayer->SetPosition(sf::Vector2f(175, 350));
	myEM.Initialize();
	myObjM.Initialize();
	myCM.Initialize();

	myPortal.Initialize();
	myPortal.SetPosition(sf::Vector2f(1000, 350));

	printf("\nInitialized WorldManager.");

}

void WorldManager::LoadContent(TextureContainer &aTxtrContainer, sf::RenderWindow &aWindow)
{
	myPlayer->LoadContent(aTxtrContainer);
	myEM.LoadContent(aTxtrContainer);
	myObjM.LoadContent(aTxtrContainer);
	myPortal.LoadContent(aTxtrContainer);

	printf("\nLoaded WorldManager Content.");
}

void WorldManager::Update(float & aDeltaTime)
{
	if (myCM.GetNextLocaleFlag())
	{
		NextLocale();
	}

	if (myCM.GetOpenPortalFlag() || *myLocale == Locale::START)
	{
		printf("Locale: %i", myLocale);
		myPortal.Update(aDeltaTime);
	}

	/*
		The switch statement is for optimization
		Makes sure you don't have to go 
		through enemy updates or object updates
		unless you actually have to.
	*/
	myCM.Update(myPlayer, myEM.GetEnemies(), myObjM.GetObjects(), myPortal, *myLocale);
	myPlayer->Update(aDeltaTime);
	

	switch (*myLocale) 
	{	
		case Locale::PUZZLE_00:
		case Locale::PUZZLE_01:
			myObjM.Update(aDeltaTime, myPlayer->GetVelocity());
			break;

		case Locale::ENEMY_FIGHT_SCENE:
			myEM.Update(aDeltaTime, myPlayer->GetPosition());
			break;
		case Locale::BOSS:
			//TODO: Include Boss Update
			break;
	}
}

void WorldManager::Render(sf::RenderWindow & aWindow)
{
	/*
		The switch statement is for optimization
		Makes sure you don't have to go 
		through enemy renders or object renders
		unless you actually have to.
	*/

	switch (*myLocale)
	{
		case Locale::PUZZLE_00:
		case Locale::PUZZLE_01:
			myObjM.Render(aWindow);
			break;
		case Locale::ENEMY_FIGHT_SCENE:
			myEM.Render(aWindow);
			break;
		case Locale::BOSS:
			//TODO: Include Boss Render
			break;
	}

	if (myCM.GetOpenPortalFlag() || *myLocale == Locale::START)
	{
		myPortal.Render(aWindow);
	}

	myPlayer->Render(aWindow);
}

void WorldManager::LateRender(sf::RenderWindow & aWindow)
{
}

Locale * WorldManager::GetLocale()
{
	return myLocale;
}

void WorldManager::SetLocale(Locale * aLocale)
{
	myLocale = aLocale;
}

Player * WorldManager::GetPlayer()
{
	return myPlayer;
}

void WorldManager::NextLocale()
{
	myCM.SetNextLocaleFlag(false);
	myCM.SetOpenPortalFlag(false);
	myPlayer->SetPosition(sf::Vector2f(175, 350));
	myLocale++;
}
