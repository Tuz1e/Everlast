#include "pch.h"
#include "UIManager.h"

//TODO: Turn all text objects into an array

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UIManager::Initialize() 
{

	if (!myFont.loadFromFile("Content/atwriter.ttf")) 
	{
		std::cout << "ERROR: Loading File; atwriter.ttf" << std::endl;
	}

	for (size_t i = 0; i < static_cast<int>(UIElements::UIElementLength); i++)
	{
		myUIElements.push_back(new sf::Text);
		myUIElements[i]->setFont(myFont);
		myUIElements[i]->setPosition(sf::Vector2f(10, 10 + (i * 30)));
		myUIElements[i]->setCharacterSize(15);
		myUIElements[i]->setFillColor(sf::Color::Red);
		myUIElements[i]->setOutlineThickness(5);
	}

	myUIElements[HEALTH]->setString("Health: 0");
	myUIElements[ATTACK_KEY]->setString("Attack: LMB");
	myUIElements[ITEM_PICKUP_KEY]->setString("Carry/Use Items: MMB");
}

void UIManager::Update(float & aDeltaTime, Player * aPlayer)
{
	myUIElements[HEALTH]->setString("Health: " + std::to_string((aPlayer->GetHealth() >= 0) ? aPlayer->GetHealth() : 0));
}

void UIManager::LateRender(sf::RenderWindow & aWindow)
{
	for (size_t i = 0; i < myUIElements.size(); i++)
	{
		aWindow.draw(*myUIElements[i]);
	}
}
