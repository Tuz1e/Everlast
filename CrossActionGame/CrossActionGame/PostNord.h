#ifndef NORDPOST_H
#define NORDPOST_H

#include "Subscriber.h"

class PostNord
{
public:
	~PostNord();

	static void Message(const MessageType &aMessage);
	static void Subscribe(Subscriber *aSubscriber);

private:
	PostNord();

	static std::vector<Subscriber*> mySubscribers;
};

#endif