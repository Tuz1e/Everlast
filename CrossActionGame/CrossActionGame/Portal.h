#ifndef PORTAL_H
#define PORTAL_H

#include "Instance.h"

class Portal : public Instance
{
public:
	Portal();
	~Portal();

	void Initialize() override;
	void LoadContent(TextureContainer &aTxtrContainer) override;
	void Update(float &aDeltaTime) override;
	void Render(sf::RenderWindow & aWindow);
};

#endif