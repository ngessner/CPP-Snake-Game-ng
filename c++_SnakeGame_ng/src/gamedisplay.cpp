#include "gamedisplay.h"

void DrawGame::drawMap(int x, int y)
{ 
    cout << endl << "SCORE: " << score << endl;
    getTailPos(x, y);

    // -1 because I wanted to change the boards 0 pos
    for (int i = -1; i <= HEIGHT; i++)
    {
        if (i == -1)
        {
            cout << " ";
        }
        else
        {
            cout << "|";
        }
        for (int j = 0; j < WIDTH; j++)
        {         
            if (i == -1 || i == HEIGHT)
            {
                cout << "_";
            }         
            else if (j == x && i == y)
            {             
                cout << "S";
            }
            // spawn fruit
            else if (j == fruitX && i == fruitY)
            {
                cout << "@";
            }
            // eat fruit (generates new rand pos)
            else if (x == fruitX && y == fruitY)
            {
                drawFruit();
            }
            // increase tail
            else
            {
                increaseTail(i, j);
            }
        }
        if (i == -1)
        {
            cout << " " << endl;
        }
        else
        {
            cout << "|" << endl;
        }
    }
}

void DrawGame::increaseTail(int i, int j)
{
    bool canPrint = false;
    for (int k = 1; k <= tailC; k++)
    {
        if (i == tailY[k] && j == tailX[k])
        {
            cout << "s";
            canPrint = true;
        }
    }
    if (!canPrint)
    {
        cout << " ";
    }
}

bool DrawGame::hitBorder(int x, int y)
{
    if (x == WIDTH || x < 0 || y == HEIGHT || y < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DrawGame::hitTail(int x, int y)
{
    for (int k = 1; k <= tailC; k++)
    {
        if (y == tailY[k] && x == tailX[k])
        {
            return true;
        }        
    }
    return false;
}

void DrawGame::drawFruit()
{    
    srand((unsigned int)time(NULL));

    tailC++;
    score += 10;           
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;

    cout << " ";
}

void DrawGame::getTailPos(int x, int y)
{
    for (int i = tailC; i > 0; i--)
    {     
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    tailX[0] = x;
    tailY[0] = y;
}

void DrawGame::finalScore()
{
    cout << "Your Final Score Was: " << score << endl;
}


