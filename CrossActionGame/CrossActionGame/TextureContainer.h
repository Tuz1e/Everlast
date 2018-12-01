#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#define PLAYER_RUN_TEXTURE "Content/Textures/Player/player_run.png"
#define PLAYER_IDLE_TEXTURE "Content/Textures/Player/player_idle.png"

#include <SFML/Graphics/Texture.hpp>
#include <vector>

class TextureContainer
{
public:
	TextureContainer();
	~TextureContainer();

	sf::Texture *GetTexture(unsigned anIndex);

	std::vector<sf::Texture*> myTextures;
	std::vector<sf::Texture*> myTiles;
};

#endif