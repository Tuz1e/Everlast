#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include "Player.h"
#include "EnemyManager.h"
#include "CollisionManager.h"
#include "ObjectManager.h"
#include "Portal.h"

class WorldManager
{
public:
	WorldManager();
	~WorldManager();

	void Initialize();
	void LoadContent(TextureContainer &aTxtrContainer, sf::RenderWindow &aWindow);
	void Update(float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);
	void LateRender(sf::RenderWindow &aWindow);
	Locale *GetLocale();
	void SetLocale(Locale *aLocale);
	Player *GetPlayer();
	void NextLocale();

private:
	Locale *myLocale;
	Player *myPlayer;
	EnemyManager myEM;
	CollisionManager myCM;
	ObjectManager myObjM;
	Portal myPortal;
};

#endif