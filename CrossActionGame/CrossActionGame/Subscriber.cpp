#include "pch.h"
#include "Subscriber.h"
#include "PostNord.h"

Subscriber::Subscriber()
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::SendMessage(Memorandum *aMemorandum, const MessageType &aMessage)
{
	PostNord::Message(aMemorandum, aMessage);
}