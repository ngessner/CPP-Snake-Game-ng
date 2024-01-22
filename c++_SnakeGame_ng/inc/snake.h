#ifndef SNAKE_H 
#define SNAKE_H 

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std; 

class Snake
{
private:					
	static const int KEY_UP = 72;
	static const int KEY_DOWN = 80;
	static const int KEY_LEFT = 75;
	static const int KEY_RIGHT = 77;	
	int userInput;
	int speedX = 50;
	int speedY = 75;

public:		
	int xPos = 3;
	int yPos = 5;

	void input();																				
	void move();																																																															
};


#endif
