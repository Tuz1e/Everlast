#include "pch.h"
#include "Memorandum.h"


Memorandum::Memorandum()
{
}


Memorandum::~Memorandum()
{
}

void Memorandum::SetBoundingBox(sf::FloatRect aBoundingBox)
{
}

sf::FloatRect Memorandum::GetBoundingBox()
{
	return myBoundingBox;
}

void Memorandum::SetVector(sf::Vector2f aVector)
{
	myVector = aVector;
}

sf::Vector2f Memorandum::GetVector()
{
	return myVector;
}
