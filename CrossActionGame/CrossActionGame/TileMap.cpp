#include "pch.h"
#include "TileMap.h"

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::LoadContent()
{
	myTMapTxtFile = "/Content/Maps/Jungle/jungle_tilemap.xml";
	myTMapTxtrFile = LoadFromXml(myTMapTxtFile, "file");
	myTMapSize = sf::Vector2i
	(
		std::stoi(LoadFromXml(myTMapTxtFile, "width")),
		std::stoi(LoadFromXml(myTMapTxtFile, "height"))
	);
	myTiles.resize(myTMapSize.x*myTMapSize.y);

	myTileIdsString = LoadFromXml(myTMapTxtFile, "map");

	std::istringstream tempISStream(myTileIdsString);
	std::vector<int> tempIds{ std::istream_iterator<int>(tempISStream),
					   std::istream_iterator<int>() };
	std::copy(tempIds.begin(), tempIds.end(), std::ostream_iterator<int>(std::cout, ","));



	int myTileCounter = myTMapSize.x*myTMapSize.y;

	for (size_t i = 0; i < myTileCounter; i++)
	{
		myTiles[i]->myTileId = tempIds[i];
	}


	//TODO: Set texture
	myTileCounter = 0;
	for (size_t i = 0; i < myTMapSize.y; i++)
	{
		myTiles[myTileCounter]->myPosition->y = i * 16;
		for (size_t j = 0; j < myTMapSize.x; j++)
		{
			myTiles[myTileCounter]->myPosition->x = j * 16;
		}
		myTileCounter++;
	}
}


std::string TileMap::LoadFromXml(const std::string &aPath, const std::string &aFindLine)
{
	std::string tempLine; //The line to return
	std::ifstream tempIn(aPath);
	while (std::getline(tempIn, tempLine))
	{
		int tempFind = (int)tempLine.find(aFindLine);
		if (tempFind != std::string::npos)
		{
			tempFind = -1;
			do
			{
				tempFind = (int)tempLine.find(aFindLine, tempFind + 1);
				if (tempFind != -1)
				{
					//Removes the specified string to get what is in between.
					tempLine = tempLine.substr(0, tempFind) + tempLine.substr(tempFind + aFindLine.length());
				}
			} while (tempFind != -1);
			//tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), &ispunct), tempLine.end());
			tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), &isspace), tempLine.end());
			break;
		}
	}
	return tempLine;
}

std::string TileMap::LoadIdFromXml(const std::string & aPath, const std::string & aFindLine)
{
	std::string tempLine; //The line to return
	std::ifstream tempIn(aPath);
	while (std::getline(tempIn, tempLine)) 
	{
		int tempFind = static_cast<int>(tempLine.find(aFindLine));
	}

	return 0;
}
