#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Memorandum.h"

enum MessageType
{
	OpenPortal,

	Count
};

class Subscriber
{
public:
	Subscriber();
	~Subscriber();

	void SendMessage(const MessageType &aMessage);
	virtual void ReceiveMessage(const MessageType &aMessage) = 0;
	//TODO: Add MessageType
};

#endif