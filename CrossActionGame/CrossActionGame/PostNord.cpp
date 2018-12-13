#include "pch.h"
#include "PostNord.h"
#include <iostream>

//CU::GrowingArray< CU::GrowingArray<Subscriber*>> PostMaster::mySubscribers;

std::vector<std::vector<Subscriber*>> PostNord::mySubscribers;

PostNord::~PostNord()
{
}

void PostNord::Initialize()
{
	for (size_t i = 0; i < MessageCount; i++)
	{
		std::vector<Subscriber*> tempSub;
		mySubscribers.push_back(tempSub);
	}
}

void PostNord::Message(const MessageType & aMessage)
{
	for (int i = 0; i < mySubscribers.size(); i++)
	{
		mySubscribers[aMessage][i]->ReceiveMessage(aMessage);
	}
}

void PostNord::Subscribe(Subscriber *aSubscriber, const MessageType &aMessage)
{
	mySubscribers[aMessage].push_back(aSubscriber);
}