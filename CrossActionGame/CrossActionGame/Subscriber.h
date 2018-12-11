#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

enum MessageType
{
	PlayerLocation,
	MessageCount
};

class Subscriber
{
public:
	Subscriber();
	virtual ~Subscriber();

	void SendMessage(const MessageType &aMessage);
	virtual void ReceiveMessage(const MessageType &aMessage) = 0;

protected:
};

#endif