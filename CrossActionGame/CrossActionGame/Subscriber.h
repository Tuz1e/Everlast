#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Memorandum.h"

enum MessageType
{
	PlayerHit,
	EnemyHit,

	MessageCount
};

class Subscriber
{
public:
	Subscriber();
	~Subscriber();

	void SendMessage(const Memorandum &aMemorandum, const MessageType &aMessage);
	virtual void ReceiveMessage(const Memorandum &aMemorandum, const MessageType &aMessage) = 0;
	//TODO: Add MessageType
};

#endif