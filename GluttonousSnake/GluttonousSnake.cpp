// GluttonousSnake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include <time.h>

using namespace std;

//display
inline void display(char gsDomain[][22], int level, int moveSpeed) {
	system("cls"); //清屏
	cout << endl << endl;
	for (int i = 0; i < 22; i++) {
		cout << "\t";
		for (int j = 0; j < 22; j++) {
			cout << gsDomain[i][j] << " ";
		}
		if (i == 0) {
			cout << "\tLevel: " << level;
		}
		else if (i == 3) {
			cout << "\t自动前进时间";
		}
		else if (i == 5) {
			cout << "\t间隔: " << moveSpeed << "ms";
		}

		cout << endl;
	}
}


int main()
{
	char gsDomain[22][22]; //Gluttonous snake activity area (including walls)
	//initialize Gluttonous snake activity area (not include wall)
	for (int i = 1; i <= 21; i++) {
		for (int j = 1; j <= 21; j++)
			gsDomain[i][j] = ' ';
	}
	//initialize Gluttonous snake activity area's top and bottom walls.
	for (int i = 0; i < 22; i++) {
		gsDomain[0][i] = gsDomain[21][i] = '-';
	}
	//initialize Gluttonous snake activity area's left and right walls.
	for (int i = 0; i < 21; i++) {
		gsDomain[i][0] = gsDomain[i][24] = '|';
	}
	//initialize snake body.
	for (int i = 1; i <= 3; i++) {
		gsDomain[i][i] = '*';
	}
	//initialize snake head.
	gsDomain[1][4] = '#';

	int snake[2][100]; //record Gluttonous snake every time showed up position's coordinates;
	for (int i = 0; i < 4; i++) {
		snake[0][i] = 1; //record Gluttonous snake's position of X coordinates;
		snake[1][i] = i + 1; //record Gluttonous snake's position of Y coordinates;
	}
	int head = 3, tail = 0, length = 4;

	int beanX, beanY; //beans appear position
	srand(time(0));
	do {
		beanX = rand() % 20 + 1;
		beanY = rand() % 20 + 1;
	} while (gsDomain[beanX][beanY] != ' ');
	gsDomain[beanX][beanY] = '*'; // bean

	cout << "\n\n\t\t Gluttonous snake game is about to begin!\n";
	long start;
	int level = 1, moveSpeed = 1000;
	for (int i = 3; i >= 0; i--) {
		start = clock();
		while (clock() - start <= 1000) {}
		system("cls");
		if (i) {
			cout << "\n\n\t\t Enter the game countdown: " << i << endl;
		}
		else display(gsDomain, level, moveSpeed);
	}

	char direction = 77; //Gluton
	
	

	system("pause");
    return 0;
}

