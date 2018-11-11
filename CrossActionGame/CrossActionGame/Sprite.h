#ifndef SPRITE_H
#define SPRITE_H
class Sprite
{
public:
	Sprite();
	~Sprite();

	void LoadFromFile(const std::string &aFileName);

	sf::Texture GetTexture();
	void SetTexture(sf::Texture aTexture);
	sf::Sprite GetSprite();
	void SetSprite(sf::Sprite aSprite);
	void SetPosition(sf::Vector2f aPosition);
	void SetAnimation(int aRowCount, int aColumnCount, int aFrameCount, float aFramerate);
	void UpdateAnimation(float &aDeltaTime, sf::Vector2f &aPosition, bool aMovingFlag);

	void SetScale(float aX, float aY);
	void Render(sf::RenderWindow &aWindow);

private:
	sf::Texture myTexture;
	sf::Sprite mySprite;
	std::string myContentFolder;
	int
		myFrameCount,
		myRowCount,
		myColumnCount,
		myFramerate;
	float
		myCurrentFrame,
		myScale;
};

#endif