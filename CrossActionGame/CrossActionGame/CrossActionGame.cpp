// CrossActionGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Game.h"
#include <chrono>
#include <time.h>
#include <thread>
#include <sys/timeb.h>
#include <thread>
#include <atomic>

timeb myTb;

int main()
{
	Game tempGame;
	bool tempRunFlag = true;

	auto tempNs = std::chrono::high_resolution_clock::now();
	long tempPreviousTime =
		(long)std::chrono::duration_cast<std::chrono::nanoseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count(); //Gets previous time
	float tempNsPerTick = 1000000000 / 60.0f; //Nanoseconds per tick

	int tempTicks = 0;
	int tempFrames = 0;

	long tempLastTimer = (long)std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();
	float tempDelta = 0.0f;

	sf::RenderWindow tempWindow(sf::VideoMode(1280, 720), "Everlast");
	tempGame.Initialize();
	tempGame.LoadContent(tempWindow);

	while (tempRunFlag && tempWindow.isOpen())
	{
		tempNs = std::chrono::high_resolution_clock::now(); //Gets current time in nanoseconds

		long tempNow =
			(long)std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count();
		tempDelta += (tempNow - tempPreviousTime) / tempNsPerTick;
		tempPreviousTime = tempNow;

		sf::Event tempEvent;
		while (tempWindow.pollEvent(tempEvent))
		{
			if (tempEvent.type == sf::Event::Closed) { tempWindow.close(); } //Makes sure the game closes when X is pressed.
		}

		while (tempDelta >= 1) //Update once every 1/60th second
		{
			tempTicks++;
			tempGame.Update(tempDelta); //Update
			tempDelta--;
		}

		tempFrames++; //Updates frames
		tempWindow.clear();
		tempGame.Render(tempWindow);
		tempGame.LateRender(tempWindow); //To render UI elements, on top of normal game ones.
		tempWindow.display();

		if ((long)std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count() - tempLastTimer > 1000)
		{
			printf("\n\nFPS: %i", tempFrames);
			printf("\nDELTA: %f", tempDelta);
			tempLastTimer += 1000;
			tempTicks = 0;
			tempFrames = 0;
		}
	}
}

void Update()
{
}