#include "pch.h"
#include "XMark.h"


XMark::XMark()
{
}


XMark::~XMark()
{
}

void XMark::Initialize()
{
	myObjType = ObjectTypes::XMARK;
}

void XMark::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(TextureID::XMARK_IDLE, 0, &aTxtrContainer);
	mySprite.SetTexture(mySpriteSheets[myActionState]->myTexture);

	mySprite.SetScale(0.05f, 0.05f);
	mySprite.Flip(RIGHT);
	mySprite.SetPosition(myPosition.x, myPosition.y);


	myHitbox.setSize
	(
		sf::Vector2f
		(
			mySprite.GetTexture()->getSize().x * mySprite.GetSprite().getScale().x,
			mySprite.GetTexture()->getSize().y * mySprite.GetSprite().getScale().y
		)
	);
	myHitbox.setTextureRect
	(
		sf::IntRect
		(
			myPosition.x - (mySprite.GetTexture()->getSize().x/4),
			myPosition.y - (mySprite.GetTexture()->getSize().y/4),
			(mySprite.GetSprite().getGlobalBounds().width * mySprite.GetSprite().getScale().x) / 2,
			(mySprite.GetSprite().getGlobalBounds().height * mySprite.GetSprite().getScale().y) / 2
		)
	);

	myHitbox.setOutlineColor(sf::Color::Magenta);
	myHitbox.setOutlineThickness(2.0f);

	myHitbox.setPosition(myPosition);
}

void XMark::Update(float & aDeltaTime, const sf::Vector2f & aVelocity)
{
}

void XMark::Render(sf::RenderWindow & aWindow)
{
	//aWindow.draw(myHitbox);
	mySprite.Render(aWindow);
}
