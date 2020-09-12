#include <stdio.h>
#include <windows.h>
#include <conio.h>
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int , int);


int main()
{
	char ch = ' ';
	int x = 30, y = 18,direc = 0;
	setcursor(0);
	draw_ship(x,y);
	do
	{
		printf("1\n");
		if (_kbhit)
		{
			ch = _getch();
			if (ch == 'a')
			{
				direc = 1;
				/*erase_ship(x, y);
				draw_ship(--x, y);*/
			}
			if (ch == 'd')
			{
				direc = 2;
				/*erase_ship(x, y);
				draw_ship(++x, y);*/
			}
			if (ch == 'w' && y>0)
			{
				/*erase_ship(x, y);
				draw_ship(x, --y);*/
			}
			if (ch == 's')
			{
				direc = 0;
				/*erase_ship(x, y);
				draw_ship(x, ++y);*/
			}
			//fflush(stdin);
		}
		if (direc == 1 && x > 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direc == 2 && x < 72)
		{
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}

void draw_ship(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2, 4);
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(0, 0);
	printf("       ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
