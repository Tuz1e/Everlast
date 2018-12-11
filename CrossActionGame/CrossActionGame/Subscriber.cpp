#include "pch.h"
#include "Subscriber.h"
#include "PostNord.h"

Subscriber::Subscriber()
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::SendMessage(const MessageType &aMessage)
{
	PostNord::Message(aMessage);
}