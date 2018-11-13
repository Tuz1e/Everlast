#ifndef TILE_H
#define TILE_H

class Tile
{
public:
	Tile();
	~Tile();

	void Update(float &aDeltaTime, int aX, int aY);
	void Render(sf::RenderWindow &aWindow);
};

#endif