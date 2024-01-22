#ifndef DISPLAY_H // if not defined, define it, if it already is defined, don't do this
#define DISPLAY_H // if this is included multiple times for some reason in the same source, it could cause errors or some shit.

#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

class DrawGame
{
private:	
	 const int HEIGHT = 20;
	 const int WIDTH = 60;
	 int score = 0;
	 int fruitX; 
	 int fruitY; 	 

	 int tailX[1000];
	 int tailY[1000];
	 int tailC = 0;

public:
	DrawGame()
	{
		srand((unsigned int)time(NULL));

		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
	}

	void drawMap(int, int);
	void getTailPos(int, int);
	void drawFruit();
	bool hitBorder(int, int);
	void finalScore();
	void increaseTail(int, int);
	bool hitTail(int, int);

};

#endif
