#ifndef BARREL_H
#define BARREL_H

#include "Object.h"

class Barrel : public Object
{
public:
	Barrel();
	~Barrel();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float & aDeltaTime, const sf::Vector2f & aVelocity) override;
	void Render(sf::RenderWindow &aWindow) override;
};

#endif