#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML\Graphics\Vertex.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>

class TileMap
{
public:
	TileMap();
	~TileMap();

	void LoadContent();

	std::string LoadFromXml(const std::string &aPath, const std::string &aFindLine);

	sf::Vertex myTiles;
	std::string 
		myTMapTxtrFile,
		myTMapTxtFile;
	sf::Vector2i myTMapSize;
};

#endif