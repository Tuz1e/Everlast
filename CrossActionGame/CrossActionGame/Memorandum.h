#ifndef MEMORANDUM_H
#define MEMORANDUM_H

class Memorandum
{
public:
	Memorandum();
	~Memorandum();

	void SetBoundingBox(sf::FloatRect aBoundingBox);
	sf::FloatRect GetBoundingBox();

	void SetVector(sf::Vector2f aVector);
	sf::Vector2f GetVector();

	void SetInteger(const int &anInteger);
	int GetInteger();

private:
	sf::FloatRect myBoundingBox;
	sf::Vector2f myVector;
	int myInteger;
};

#endif