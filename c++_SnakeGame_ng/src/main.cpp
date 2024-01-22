#include "gamedisplay.h"
#include "snake.h"

int main()
{
	DrawGame graphics;
	Snake snake;
	bool gameOver = false;			

    cout << "Press an arrow key to play!" << std::endl;
    snake.input();
    system("CLS");

    while (!gameOver)
    {        
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        graphics.drawMap(snake.xPos, snake.yPos);
       
        snake.move();
        
        if (_kbhit())
        {
            snake.input();
        }

        // death conditions
        if (graphics.hitBorder(snake.xPos, snake.yPos) || graphics.hitTail(snake.xPos, snake.yPos))
        {
            system("CLS");
            gameOver = true;            
            cout << "GAME OVER" << endl;
            graphics.finalScore();
        }               
    }    
}


