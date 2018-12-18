#include "pch.h"
#include "TextureContainer.h"

TextureContainer::TextureContainer()
{
	try
	{
		SetTextures(PLAYER_IDLE, PLAYER_IDLE_TEXTURE, 1, 13, 13);
		SetTextures(PLAYER_WALK, PLAYER_RUN_TEXTURE, 1, 8, 8);
		SetTextures(PLAYER_ATTACK, PLAYER_ATTACK_TEXTURE, 1, 4, 4);
		SetTextures(PLAYER_HIT, PLAYER_HIT_TEXTURE, 1, 4, 4);

		SetTextures(SKELETON_IDLE, SKELETON_IDLE_TEXTURE, 1, 11, 11);
		SetTextures(SKELETON_WALK, SKELETON_WALK_TEXTURE, 1, 13, 13);
		SetTextures(SKELETON_ATTACK, SKELETON_ATTACK_TEXTURE, 1, 18, 18);
		SetTextures(SKELETON_HIT, SKELETON_HIT_TEXTURE, 1, 8, 8);
		SetTextures(BARREL_IDLE, BARREL_IDLE_TEXTURE, 1, 1, 1);

		printf("\nLoaded textures.");
	}
	catch (std::string e)
	{
		printf("\nUnable to load textures.");
	}
}

TextureContainer::~TextureContainer()
{
	for (Textures* txtrptr : myTextures)
	{
		PtrDelete(txtrptr->myTexture);
		PtrDelete(txtrptr);
	}
	printf("\nRemoved TxtrContainr TxtrPtr.");
}

void TextureContainer::SetTextures(unsigned anIndex, const std::string &aLocation, const int & aRowCount, const int & aColumnCount, const int & aFrameCount)
{
	myTextures.push_back(new Textures);
	myTextures[anIndex]->myTexture->loadFromFile(aLocation);
	myTextures[anIndex]->myRows = aRowCount;
	myTextures[anIndex]->myColumns = aColumnCount;
	myTextures[anIndex]->myFrames = aFrameCount;
}

///Returns Textures: 2D Texture, Row Count, Column Count, Frame Count
Textures * TextureContainer::GetTextures(unsigned anIndex)
{
	return myTextures[anIndex];
}

//Returns 2D Texture
sf::Texture *TextureContainer::GetTexture(unsigned anIndex)
{
	return myTextures[anIndex]->myTexture;
}

int TextureContainer::GetRows(unsigned anIndex)
{
	return myTextures[anIndex]->myRows;
}

int TextureContainer::GetColumns(unsigned anIndex)
{
	return myTextures[anIndex]->myColumns;
}

int TextureContainer::GetFrames(unsigned anIndex)
{
	return myTextures[anIndex]->myFrames;
}