#ifndef INPUT_H
#define INPUT_H

enum Key
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	MOUSE_LEFT,
	MOUSE_RIGHT,
	NONE
};

class Input
{
public:
	~Input();

	static Key GetKey();

private:
	Input();
	static Key myKeyPressed;
};

#endif