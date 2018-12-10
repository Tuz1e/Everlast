#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#define PLAYER_RUN_TEXTURE "Content/Textures/Player/player_run.png"
#define PLAYER_IDLE_TEXTURE "Content/Textures/Player/player_idle.png"

//#define SKELETON_IDLE_TEXTURE "Content/Textures/Enemies/barrel.png"
#define SKELETON_WALK_TEXTURE "Content/Textures/Enemy/skeleton_walk.png"

#include <vector>

class TextureContainer
{
public:
	TextureContainer();
	~TextureContainer();
	void SetTextures(unsigned anIndex, const std::string &aLocation, const int &aRowCount, const int &aColumnCount, const int &aFrameCount);

	Textures *GetTextures(unsigned anIndex);
	sf::Texture *GetTexture(unsigned anIndex);
	int GetRows(unsigned anIndex);
	int GetColumns(unsigned anIndex);
	int GetFrames(unsigned anIndex);

	std::vector<Textures*> myTextures;
};

#endif