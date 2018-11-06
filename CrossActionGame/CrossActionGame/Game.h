#ifndef GAME_H
#define GAME_H

#define VERSION 0.01
#define AUTHOR "Pontuz Klasson"
#define REPOSITORY "https://github.com/Tuz1e/Everlast"

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Update(const double &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);

	sf::CircleShape myCircle;
	sf::Vector2f myPosition;
	sf::Vector2f myVelocity;
};

#endif