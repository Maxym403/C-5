// ДЗ 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{
	//    const int size = 20;
	//    int ar[size];
	//    srand(time(0));
	//    for (int i = 0; i < size; i++) {
	//        ar[i] = rand() % 100 + 1;

	//    }

	//    for (int i = 0; i < size; i++) {
	//        if (i % 2 == 0) {
	//            cout << ar[i]<<"\n";
	//        }
	//    }
	//    cout << "\n";
	//    return 0;

	//	const int SIZE = 5;
	//	int ar[5] = { 1,2,3,4,5 };
	//	cout << ar[0] << "\n";
	//	cout << ar[1] << "\n";
	//	cout << ar[2] << "\n";
	//	cout << ar[3] << "\n";
	//	cout << ar[4] << "\n";
	//	for (int i = SIZE - 1; i >= 0; i--) {
	//		cout << ar[i] << "\n";
	//	}

	//	const int SIZE = 20;
	//	int ar[SIZE];
	//	int sum = 0;
	//	srand(time(0));
	//	for (int i = 0; i < SIZE; i++) {
	//
	//
	//		ar[i] = rand() % 41 - 30;
	//	}
	//	for (int i = 0; i < SIZE; i++) {
	//		if (ar[i] < 0) {
	//			break;
	//		}
	//		else {
	//			sum += ar[i];
	//		}
	//	}
	//	cout << sum << "\n";
	//	return 0;


	//int N, M;
	//cout << "Введіть кількість рядків (N) і стовпців (M)\n";
	//cin >> N >> M;
	//int sum = 0;
	//int maxValue = 20;
	//int minValue = 0;
	//int ar[N][M];

	//srand(time(0));
	//rand() % 21;
	//for (int i = 0; i < N; i++) {
		//for (int j = 0; j < M; j++)
			//ar[i][j] = rand() % 21;
		//sum += ar[i][j];
		//if (ar[i][j] > maxValue) maxValue = ar[i][j];
		//if (ar[i][j] < minValue) minValue = ar[i][j];

	//}
	//float arithmetic = float(sum / (N * M));
	//cout << "Сума\n" << sum;
	//cout << "Середнє арифметичне\n" << arithmetic;
	//cout << "Мінімальне\n" << minValue;
	//cout << "Максимальне\n" << maxValue;

//	int  M;
//	cout << "Введіть кількість парну  M\n";
//	cin >> M;
//	int ar[M][M];
//	int sum_main = 0;
//	int sum_side = 0;

//	srand(time(0));
//	rand() % 21;
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++){
//			ar[i][j] = rand() % 21;
//		 if (i == j) {
//			 sum_main += ar[i][j];
//
//		 }
//		 if (i + j == M - 1) {
//			 sum_side += ar[i][j];
//
//		 }
//		}
//	}
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << ar[i][j] << "\t";
//		}
//		cout << "\n";
//	}
//	cout << sum_main  <<"\n";
//	cout << sum_side << "\n";

//    const int  N = 4;
//	const int  M = 6;

//	int ar[N][M];
//	int quantity_positive = 0;
//	int quantity_negative = 0;
//	int zero = 0;

//	srand(time(0));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++){
//			ar[i][j] = rand() % 21 - 10;
//			if (ar[i][j] < 0) {
//				quantity_negative++;
//			}
//			else
//				if (ar[i][j] > 0) {
//				quantity_positive++;
//			    }
//				else {
//                  zero++;
//				}

//		}

//	}

//	cout << quantity_positive <<"\n";
//	cout << quantity_negative <<"\n";
//	cout << zero <<"\n";
//	return 0;

	srand(time(0));
	system("mode con cols=210 lines=70");
	system("title Maze");

	// hide standard console cursor
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	const int width = 75;
	const int height = 20;
	int maze[height][width];
	int coinsCollected = 0;
	int totalCoins = 0;
	int unit = 0;

	enum maze_objects { HALL, WALL, GOLD, VRAG };
	enum direction { DOWN = 80, UP = 72, LEFT = 75, RIGHT = 77 };
	enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2 };

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int random = rand() % 4;
			maze[y][x] = random;

			if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
				maze[y][x] = WALL;

			// enter and exit

			if (x == 0 && y == 2 || x == 1 && y == 2
				|| x == width - 1 && y == height - 3) {
				maze[y][x] = HALL;
			}
			if (x == width - 1 && y == height - 3) {
				cout << "Вітаємо! Ви дійшли до виходу!\n";
				break;
			}
			/////////////////////////////////////////////////////////

			if (maze[y][x] == WALL)
			{
				SetConsoleTextAttribute(h, DARKGREEN);
				cout << (char)178;
			}
			else if (maze[y][x] == GOLD)
			{
				SetConsoleTextAttribute(h, YELLOW);
				cout << (char)250;
			}
			else if (maze[y][x] == VRAG)
			{
				int r = rand() % 100; // 0...99
				if (r == 0)
				{
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
				}
				else
				{
					maze[y][x] = HALL;
					cout << " ";
				}
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}

	COORD pers = { 0, 2 };
	SetConsoleCursorPosition(h, pers);
	SetConsoleTextAttribute(h, BLUE);
	cout << (char)1;

	while (true)
	{
		int direct = _getch();
		if (direct == 224)
			direct = _getch();

		SetConsoleCursorPosition(h, pers);
		cout << " ";

		if (direct == RIGHT && maze[pers.Y][pers.X + 1] != WALL)
		{
			pers.X++;
		}
		SetConsoleCursorPosition(h, pers);
		SetConsoleTextAttribute(h, BLUE);
		cout << (char)1;

	}
	if (pers.X == width - 1 && pers.Y == height - 3) {
		cout << "Перемога – знайдено вихід\n";

	}
	if (coinsCollected == totalCoins) {
		cout << "Перемога – монети зібрано\n";
	}
	if (unit % 10 == 0) {
		int X, Y;
		while (true) {
			X = rand() % width;
			Y = rand() % height;
			if (maze[Y][X] == HALL) break;
 		}
	}

}


