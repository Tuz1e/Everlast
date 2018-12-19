#include "pch.h"
#include "Portal.h"


Portal::Portal()
{
}


Portal::~Portal()
{
}

void Portal::Initialize()
{
}

void Portal::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(TextureID::GREENPORTAL_ACTIVE, InstanceState::ACTIVE, &aTxtrContainer);
	SetSpriteSheet(TextureID::GREENPORTAL_OPENING, InstanceState::OPENING, &aTxtrContainer);
	SetSpriteSheet(TextureID::GREENPORTAL_CLOSING, InstanceState::CLOSING, &aTxtrContainer);
	SetActionState(4.5f);
	mySprite.SetScale(3.0f, 3.0f);
	mySprite.Flip(FlipSides::LEFT);

	myHitbox.setSize
	(
		sf::Vector2f
		(
			mySprite.GetTexture()->getSize().x / mySpriteSheets[myInstanceState]->myColumns,
			mySprite.GetTexture()->getSize().y / mySpriteSheets[myInstanceState]->myRows
		)
	);
	myHitbox.setTextureRect
	(
		sf::IntRect
		(
			myPosition.x - (mySprite.GetTexture()->getSize().x / 4) + 50,
			myPosition.y - (mySprite.GetTexture()->getSize().y / 4),
			mySprite.GetSprite().getGlobalBounds().width / 2 - 20,
			mySprite.GetSprite().getGlobalBounds().height / 2
		)
	);

	myHitbox.setOutlineColor(sf::Color::Magenta);
	myHitbox.setOutlineThickness(2.0f);
	myHitbox.setPosition(myPosition);
}

void Portal::Update(float & aDeltaTime)
{
	UpdateAnimation(aDeltaTime, myPosition, true);
}

void Portal::Render(sf::RenderWindow & aWindow)
{
	mySprite.Render(aWindow);
}
