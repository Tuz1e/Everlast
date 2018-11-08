#ifndef GAME_H
#define GAME_H

#define VERSION 0.01
#define AUTHOR "Pontuz Klasson"
#define REPOSITORY "https://github.com/Tuz1e/Everlast"

#include "Sprite.h"

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void LoadContent();
	void Update(const float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);

	Sprite mySprite;
	sf::Texture myTexture;
	sf::CircleShape myCircle;
	sf::Vector2f myPosition;
	sf::Vector2f myVelocity;
};

#endif