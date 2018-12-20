#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Player.h"

enum UIElements 
{
	HEALTH,
	ATTACK_KEY,
	ITEM_PICKUP_KEY,
	UIElementLength
};

class UIManager
{
public:
	UIManager();
	~UIManager();

	void Initialize();
	void Update(float &aDeltaTime, Player *aPlayer);
	void LateRender(sf::RenderWindow &aWindow);

private:
	std::vector<sf::Text*> myUIElements;
	sf::Text myHealth,
		myAttackKey,
		myItemPickup;
	sf::Font myFont;

};

#endif