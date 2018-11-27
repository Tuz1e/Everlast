#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include "SpriteAnim.h"
#include "TextureContainer.h"

enum World
{
	TOWN
};

class WorldManager
{
public:
	WorldManager();
	~WorldManager();

	void Initialize();
	void LoadContent(TextureContainer &aContainer, sf::RenderWindow &aWindow, World aLocation);
	void Update();
	void Render(sf::RenderWindow & aWindow);

private:
	std::map<int, SpriteAnim> myWorldSprites;
};

#endif