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
		mySubscribers.push_back(std::vector<Subscriber*>());
	}
}

void PostNord::Message(Memorandum *aMemorandum, const MessageType & aMessage)
{
	for (int i = 0; i < mySubscribers[aMessage].size(); i++)
	{
		mySubscribers[aMessage][i]->ReceiveMessage(aMemorandum, aMessage);
	}
}

void PostNord::Subscribe(Subscriber *aSubscriber, const MessageType &aMessage)
{
	mySubscribers[aMessage].push_back(aSubscriber);
}