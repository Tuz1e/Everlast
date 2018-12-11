#include "pch.h"
#include "PostNord.h"

PostNord::PostNord()
{
}

PostNord::~PostNord()
{
}

std::vector<Subscriber*> PostNord::mySubscribers;

void PostNord::Message(const MessageType & aMessage)
{
	for (size_t i = 0; i < mySubscribers.size(); i++)
	{
		mySubscribers[i - 1]->ReceiveMessage(aMessage);
	}
}

void PostNord::Subscribe(Subscriber *aSubscriber)
{
	mySubscribers.push_back(aSubscriber);
}