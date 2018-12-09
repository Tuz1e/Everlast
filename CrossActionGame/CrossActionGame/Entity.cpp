#include "pch.h"
#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::LoadContent(TextureContainer *aTxtrContainer)
{
}

void Entity::Update(float & aDeltaTime)
{
}

void Entity::Render(sf::RenderWindow & aWindow)
{
}

inline void Entity::SetSpriteSheet(unsigned aTxtrIndex, unsigned anIndex, TextureContainer * aTxtrContainer)
{
	mySpriteSheets.push_back(new Textures);
	mySpriteSheets[anIndex]->myTexture = aTxtrContainer->GetTexture(aTxtrIndex);
	mySpriteSheets[anIndex]->myRows = aTxtrContainer->GetRows(aTxtrIndex);
	mySpriteSheets[anIndex]->myColumns = aTxtrContainer->GetColumns(aTxtrIndex);
	mySpriteSheets[anIndex]->myFrames = aTxtrContainer->GetFrames(aTxtrIndex);
}

inline void Entity::SetSpriteTexture(sf::Texture *aTexture)
{
	mySprite.SetTexture(aTexture);
}

sf::Texture Entity::GetSpriteSheetTexture(const unsigned & anIndex)
{
	return *mySpriteSheets[anIndex]->myTexture;
}

inline void Entity::SetPosition(sf::Vector2f aPos)
{
	myPosition = aPos;
}

inline void SpriteAnim::SetTexture(sf::Texture * aTexture)
{
	mySprite.setTexture(*aTexture);
}