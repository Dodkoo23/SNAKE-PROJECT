#include <iostream>
#include <conio.h>
#include <Windows.h>


using namespace std;
bool Koniechry;
const int sirka = 30;
const int vyska = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void setup()
{
	Koniechry = false;
	dir = STOP;
	x = sirka / 2;
	y = vyska / 2;
	fruitX = rand() % sirka;
	fruitY = rand() % vyska;
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < sirka + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < vyska; i++)
	{
		for (int j = 0; j < sirka; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}

				}
				if (!print)

					cout << " ";
			}
			if (j == sirka - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < sirka + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
	cout << "==========================================================================================\n";
	cout << "    SSSSSSSSS   NN     NN       A       KK    KK   EEEEEEE\n";
	cout << "    SS          NN N   NN      A  A     KK  KK     EE\n";
	cout << "    SSSSSSSSS   NN  N  NN     A    A    KKK        EEEEEEE\n";
	cout << "           SS   NN   N NN    AAAAAAAA   KK  KK     EE\n";
	cout << "    SSSSSSSSS   NN     NN   A        A  KK    KK   EEEEEEE\n";
	cout << "==========================================================================================\n";
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			Koniechry = true;
			break;
		}

	}

}
void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
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
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	
	if (x >= sirka) x = 0; else if (x < 0) x = sirka - 1;
	if (y >= vyska) y = 0; else if (y < 0) y = vyska - 1;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			Koniechry = true;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % sirka;
		fruitY = rand() % vyska;
		nTail++;
	}


}
int main()
{
	setup();
	while (!Koniechry)
	{
		Draw();
		Input();
		logic();
		Sleep(25);
	}


	return 0;
}








