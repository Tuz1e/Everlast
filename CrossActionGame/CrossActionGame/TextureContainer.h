#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#define PLAYER_RUN 0

#define PLAYER_RUN_TEXTURE "Content/Textures/Player/player_run.png"
#define TILE_TEXTURE_00 "Content/Textures/Tiles/generic-rpg-tile09.png"

#include <SFML/Graphics/Texture.hpp>
#include <vector>

class TextureContainer
{
public:
	TextureContainer();
	~TextureContainer();

	sf::Texture *GetTexture(unsigned anIndex);
	sf::Texture *GetTile(unsigned anIndex);

	std::vector<sf::Texture*> myTextures;
	std::vector<sf::Texture*> myTiles;
};

#endif