#ifndef SPRITE_H
#define SPRITE_H

enum FlipSides
{
	LEFT,
	RIGHT
};

class SpriteAnim
{
public:
	SpriteAnim();
	~SpriteAnim();

	void LoadFromFile(const std::string &aFileName);
	void SetTexture(sf::Texture *aTexture);
	void Flip(FlipSides aSide);
	void SetSprite(sf::Sprite aSprite);
	void SetFrame(int *anIndex);
	void SetPosition(sf::Vector2f aPosition);
	void SetAnimation(int aRowCount, int aColumnCount, int aFrameCount, float aFramerate);
	void UpdateAnimation(float &aDeltaTime, sf::Vector2f &aPosition, bool aAnimateFlag);

	sf::Texture *GetTexture();
	sf::Sprite& GetSprite();

	void SetScale(float aX, float aY);
	void Render(sf::RenderWindow &aWindow);

private:
	sf::Texture *myTexture;
	sf::Sprite mySprite;
	std::string myContentFolder;
	sf::Vector2f myScale;
	int
		myFrameCount,
		myRowCount,
		myColumnCount;
	float
		myCurrentFrame,
		myFramerate;
};

#endif