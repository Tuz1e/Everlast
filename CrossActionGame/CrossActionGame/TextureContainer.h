#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#define PLAYER_IDLE_TEXTURE "Content/Textures/Player/player_idle.png"
#define PLAYER_RUN_TEXTURE "Content/Textures/Player/player_run.png"
#define PLAYER_ATTACK_TEXTURE "Content/Textures/Player/player_attack.png"
#define PLAYER_HIT_TEXTURE "Content/Textures/Player/player_hit.png"

#define SKELETON_IDLE_TEXTURE "Content/Textures/Enemy/skeleton_idle.png"
#define SKELETON_WALK_TEXTURE "Content/Textures/Enemy/skeleton_walk.png"
#define SKELETON_ATTACK_TEXTURE "Content/Textures/Enemy/skeleton_attack.png"
#define SKELETON_HIT_TEXTURE "Content/Textures/Enemy/skeleton_hit.png"

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