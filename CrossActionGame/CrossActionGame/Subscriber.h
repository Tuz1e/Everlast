#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

enum MessageType
{
	PlayerHit,
	EnemyHit,

	MessageCount
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