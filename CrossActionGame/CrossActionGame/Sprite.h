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

	void SetScale(float aX, float aY);
	void Render(sf::RenderWindow &aWindow, bool aAnimateFlag);

private:
	sf::Texture myTexture;
	sf::Sprite mySprite;
	std::string myContentFolder;
	int
		myFrameCount,
		myRowCount,
		myColumnCount;
	float
		myCurrentFrame,
		myScale;
};

#endif