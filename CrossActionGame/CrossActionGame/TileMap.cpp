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
		static_cast<int>(LoadFromXml(myTMapTxtFile, "width")),

	)
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
