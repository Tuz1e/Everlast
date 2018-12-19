#include "pch.h"
#include "Barrel.h"

Barrel::Barrel()
{
}

Barrel::~Barrel()
{
}

void Barrel::Initialize()
{
	myActionState = ActionState::IDLE;
	myPickupFlag = true;
	myObjType = ObjectTypes::BARREL;
}

void Barrel::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(TextureID::BARREL_IDLE, 0, &aTxtrContainer);
	mySprite.SetTexture(mySpriteSheets[myActionState]->myTexture);

	mySprite.SetScale(2.0f, 2.0f);
	mySprite.Flip(RIGHT);
	mySprite.SetPosition(myPosition.x, myPosition.y);


	myHitbox.setSize
	(
		sf::Vector2f
		(
			mySprite.GetTexture()->getSize().x,
			mySprite.GetTexture()->getSize().y
		)
	);
	myHitbox.setTextureRect
	(
		sf::IntRect
		(
			mySprite.GetSprite().getGlobalBounds().left,
			mySprite.GetSprite().getGlobalBounds().top,
			mySprite.GetSprite().getGlobalBounds().width,
			mySprite.GetSprite().getGlobalBounds().height / mySpriteSheets[myActionState]->myRows
		)
	);

	myHitbox.setOutlineColor(sf::Color::Magenta);
	myHitbox.setOutlineThickness(2.0f);
	myHitbox.setPosition(myPosition);
	myHitbox.setOrigin
	(
		mySprite.GetTexture()->getSize().x / mySpriteSheets[myActionState]->myColumns / 2.0f - 45.0f,
		mySprite.GetTexture()->getSize().y / mySpriteSheets[myActionState]->myRows / 2.0f - 45.0f
	);
}

void Barrel::Update(float & aDeltaTime, const sf::Vector2f & aVelocity)
{
	if (myPickedUpFlag)
	{
		CalcMove(aDeltaTime, aVelocity);
		mySprite.SetPosition(myPosition.x, myPosition.y);
		myHitbox.setPosition(myPosition);
	}
}

void Barrel::Render(sf::RenderWindow & aWindow)
{
	//aWindow.draw(myHitbox);
	mySprite.Render(aWindow);
}
