#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML\Graphics\Vertex.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <sstream>
#include <iterator>

struct Tile
{
	int myTileId;
	sf::Sprite *mySprite;
	sf::Vector2f *myPosition;
};

class TileMap
{
public:
	TileMap();
	~TileMap();

	void LoadContent();
	void Render(sf::RenderWindow &aWindow);

	std::string LoadFromXml(const std::string &aPath, const std::string &aFindLine);

	sf::Sprite mySprite;
	std::string myTileIdsString;
	std::vector<Tile*> myTiles;
	std::string
		myTMapTxtrFile,
		myTMapTxtFile;
	sf::Vector2i myTMapSize;
};

#endif