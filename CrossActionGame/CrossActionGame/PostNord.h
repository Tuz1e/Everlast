#ifndef POSTNORD_H
#define POSTNORD_H

#include "Subscriber.h"

class Memorandum;

class PostNord
{
public:
	~PostNord();

	static void Initialize();

	static void Message(const MessageType &aMessage);
	static void Subscribe(Subscriber *aSubscriber, const MessageType &aMessage);
private:
	PostNord() {};

	static std::vector<std::vector<Subscriber*>> mySubscribers;
};

#endif