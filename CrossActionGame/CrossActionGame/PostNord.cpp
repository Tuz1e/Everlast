#include "pch.h"
#include "PostNord.h"
#include <iostream>

std::vector<std::vector<Subscriber*>> PostNord::mySubscribers;

PostNord::~PostNord()
{
}

void PostNord::Initialize()
{
	for (size_t i = 0; i < MessageType::Count; i++)
	{
		mySubscribers.push_back(std::vector<Subscriber*>());
	}
}

void PostNord::Message(const MessageType & aMessage)
{
	for (int i = 0; i < mySubscribers[aMessage].size(); i++)
	{
		mySubscribers[aMessage][i]->ReceiveMessage(aMessage);
	}
}

void PostNord::Subscribe(Subscriber *aSubscriber, const MessageType &aMessage)
{
	mySubscribers[aMessage].push_back(aSubscriber);
}