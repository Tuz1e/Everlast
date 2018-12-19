#ifndef INSTANCE_H
#define INSTANCE_H

#include "Entity.h"

enum InstanceState 
{
	ACTIVE,
	OPENING,
	CLOSING,

	InstanceLength
};

class Instance : public Entity
{
public:
	Instance();
	~Instance();

	bool GetActiveFlag();
	void SetActiveFlag(bool aStatement);
	void SetActionState(const float &anAnimationSpeed) override;

protected:
	bool myActiveFlag;
	InstanceState myInstanceState;
};

#endif