#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

const int width = 95;
const int height = 20;
const char planeCharacter = 254;
const char enemyCharacter = 219;
int bulletNumber = 0;

enum WAY { UP = 1, DOWN = 2 };

struct Plane
{
	int x;
	int y;
	WAY way;
	char Character = planeCharacter;
};

struct Enemy
{
	int x;
	int y;
	char Character = enemyCharacter;
};

struct Bullet
{
	int x;
	int y;
	char Character = '*';
};

Plane plane[5];
Enemy enemy[6];
Bullet bullet[500];
char scene[height][width];
char keys[256];

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void keyboard(char keys[]) {
	for (int i = 0; i < 256; i++)
	{
		keys[i] = (char)(GetAsyncKeyState(i) >> 8);
	}
}

void printScene() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << scene[i][j];
		}
		cout << endl;
	}
}

void clearScene() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			scene[i][j] = ' ';
		}
		cout << endl;
	}
}

void hideCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void planeMove() {
	for (int i = 0; i < 5; i++)
	{
		switch (plane[0].way)
		{
		case UP:
			plane[i].y--;
			break;
		case DOWN:
			plane[i].y++;
			break;
		default:
			break;
		}
	}
}

void frame()
{
	for (int x = 0; x < width; x++)
	{
		scene[0][x] = 219;
		scene[height - 1][x] = 219;
	}

	for (int y = 0; y < height; y++)
	{
		scene[y][0] = 219;
		scene[y][width - 1] = 219;
	}

}

void createPlane() {

	plane[0].x = 1;
	plane[0].y = 5;
	plane[1].x = 2;
	plane[1].y = 6;
	plane[2].x = 3;
	plane[2].y = 7;
	plane[3].x = 2;
	plane[3].y = 8;
	plane[4].x = 1;
	plane[4].y = 9;
}

void enemyCreate() 
{
	for (int i = 0; i < 6; i++)
	{
		int _y = rand() % 20;
		enemy[i].x = 95;
		enemy[i].y = _y;
	}
}

void enemyMove() 
{
	for (int i = 0; i < 6; i++)
	{
		enemy[i].x--;
	}
	for (int i = 0; i < 6; i++)
	{
		if (enemy[i].x < 0)
		{
			enemy[i].x = 0;
		}
	}
}

void planeToScene() 
{
	for (int i = 0; i < 5; i++)
	{
		int x = plane[i].x;
		int y = plane[i].y;
		scene[y][x] = plane[i].Character;
	}
}

void bulletToScene() 
{
	for (int i = 0; i < 500; i++)
	{
		int x = bullet[i].x;
		int y = bullet[i].y;
		scene[y][x] = bullet[i].Character;
	}
}

void bulletMove() 
{
	for (int i = 0; i < bulletNumber; i++)
	{
		bullet[i].x++;
		if (bullet[i].x > 93)
		{
			bullet[i].x = 0;
			bullet[i].y = 0;
			bullet[i].Character = 219;
		}
	}
}

void enemyToScene() 
{
	for (int i = 0; i < 6; i++)
	{
		int x = enemy[i].x;
		int y = enemy[i].y;
		scene[y][x] = enemy[i].Character;
	}
}

void bulletCreate() {
	bullet[bulletNumber].x = plane[2].x + 1;
	bullet[bulletNumber].y = plane[2].y;
	bulletNumber++;
}

void dead() 
{
	for (int i = 0; i < bulletNumber; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (enemy[j].x - bullet[i].x == 1 && bullet[i].y == enemy[j].y)
			{
				bullet[i].Character = 219;
				bullet[i].x = 0;
				bullet[i].y = 0;
				enemy[j].x = 0;
				enemy[j].y = 0;
			}
		}
	}

}

void keyboardControl() 
{
	keyboard(keys);
	if (keys['W'] != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			plane[i].y--;
		}
	}
	if (keys['S'] != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			plane[i].y++;
		}
	}
	if (keys['M'] != 0)
	{
		bulletCreate();
	}
}

int main() {

	srand(time(0));

	hideCursor();
	createPlane();
	enemyCreate();

	while (true)
	{
		clearScene();
		frame();

		keyboardControl();
		enemyMove();
		bulletMove();
		planeMove();

		planeToScene();
		enemyToScene();
		bulletToScene();
		dead();

		gotoxy(0, 0);
		printScene();
		Sleep(100);
	}

	system("pause");
	return 0;
}