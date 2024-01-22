#include "snake.h"

void Snake::input()
{   
    userInput;
    int isSpec;    

    isSpec = _getch();

    if (isSpec == 224)
    {        
        userInput = _getch();        
    }  
}

void Snake::move()
{    
    switch (userInput)
    {
    case KEY_UP:    
        Sleep(speedY);
        yPos--;
        //cout << "UP" << endl;
        break;
    case KEY_DOWN:
        Sleep(speedY);
        yPos++;
        //cout << "DOWN" << endl;
        break;
    case KEY_LEFT:
        Sleep(speedX);
        xPos--;
        //cout << "LEFT" << endl;
        break;
    case KEY_RIGHT:
        Sleep(speedX);
        xPos++;
        //cout << "RIGHT" << endl;
        break;  
    }
    /*cout << "x: " << xPos << endl;
    cout << "y: " << yPos << endl; */ 
}

