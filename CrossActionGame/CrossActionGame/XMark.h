#ifndef XMARK_H
#define XMARK_H

#include "Object.h"

class XMark : public Object
{
public:
	XMark();
	~XMark();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float & aDeltaTime, const sf::Vector2f & aVelocity) override;
	void Render(sf::RenderWindow &aWindow) override;
};

#endif