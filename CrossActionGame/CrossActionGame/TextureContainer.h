#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#pragma region TextureLocations

#define PLAYER_IDLE_TEXTURE "Content/Textures/Player/player_idle.png"
#define PLAYER_RUN_TEXTURE "Content/Textures/Player/player_run.png"
#define PLAYER_ATTACK_TEXTURE "Content/Textures/Player/player_attack.png"
#define PLAYER_HIT_TEXTURE "Content/Textures/Player/player_hit.png"

#define SKELETON_IDLE_TEXTURE "Content/Textures/Enemy/skeleton_idle.png"
#define SKELETON_WALK_TEXTURE "Content/Textures/Enemy/skeleton_walk.png"
#define SKELETON_ATTACK_TEXTURE "Content/Textures/Enemy/skeleton_attack.png"
#define SKELETON_HIT_TEXTURE "Content/Textures/Enemy/skeleton_hit.png"

#define BARREL_IDLE_TEXTURE "Content/Textures/Objects/barrel.png"
#define XMARK_IDLE_TEXTURE "Content/Textures/Objects/xmark.png"

#define GREENPORTAL_ACTIVE_TEXTURE "Content/Textures/Effects/greenportal_spritesheet_active.png"
#define GREENPORTAL_OPENING_TEXTURE "Content/Textures/Effects/greenportal_spritesheet_opening.png"
#define GREENPORTAL_CLOSING_TEXTURE "Content/Textures/Effects/greenportal_spritesheet_closing.png"

#define PURPLEPORTAL_ACTIVE_TEXTURE "Content/Textures/Effects/purpleportal_spritesheet_active.png"
#define PURPLEPORTAL_OPENING_TEXTURE "Content/Textures/Effects/purpleportal_spritesheet_opening.png"
#define PURPLEPORTAL_CLOSING_TEXTURE "Content/Textures/Effects/purpleportal_spritesheet_closing.png"

#pragma endregion Contains all the texture locations

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