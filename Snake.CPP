#include<iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool gameOver;

//Size of the screen.
const int width = 20;
const int height = 20;

//Head position, fruit position,
int x, y, fruitX, fruitY, score;

//press keys, change direction
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

//The tail of the snake. Create 2 arrays that work as pairs
int tailx[100], taily[100];
int nTail;//How long the tail currently is





void Setup(){
	gameOver = false;

	//snake won't move till we start moving it, and will start at the center of the screen.
	dir = STOP;
	x = width / 2;
	y = height / 2;

	//Fruit position random
	fruitX = rand() % width;
	fruitY = rand() % height;
	
	score = 0;
}

void Draw() {
	system("cls"); //This will clear the screen for windows.
	for (int i = 0, i < width+2; i++) 
		cout << "#";
	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#";
			
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "F";

			else {
				bool print = false; //this boolean will allow us to draw the tails.

				for (int k = 0; k < nTail; k++) {
					if (tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						print = true;
					}
					if (!print)
						cout << " ";
				}
			}
			


			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0, i < width+2; i++) 
		cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;

	

}

void Input() {
	if (_kbhit())//return positive if keyboard is pressed
	{
		switch (_getch())//return our ASCII valur of our character that was pressed.
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir=RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {
	int prevX = tailx[0];
	int prevY = taily[0];
	int prev2X, prev2Y;//make sure the tail follows the head
	tailx[0] = x; 
	taily[0] = y;



	for (int i = 1; i < nTail; i++) {//this is where our new tail must appear.
		prev2X = tailx[i];
		prev2Y = taily[i];
		tailx[i] = prevX;
		taily[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}




	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y++;
		break;
	case DOWN:
		y--;
		break;
	default:
		break;
	}

  /*if (x > width || x < 0 || y > height ||y < 0) terminate the game if we go out of the frame
		gameOver = true;*/

	//if the player touches the endges of the screen, he or she will appear on the opposite side.
	if (x >= width)
		x = 0;
	else if (x < 0)
		x = width - 1;
	else if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;



	for (int i = 0; i < nTail; i++)
		if (tailx[i] == x && taily[i] == y)//IF the player hits himself
			gameOver = true; 

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
		
	
}


int main() {

	Setup(!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(10); //slows down the game. Use this for windows 
	}
	return 0;
}
