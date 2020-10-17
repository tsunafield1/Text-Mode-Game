#include <stdio.h>
#include <windows.h>
#include <conio.h>
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int , int);
void draw_bullet(int, int);
void erase_bullet(int, int);

int main()
{
	bool b[5] = { 0,0,0,0,0 };
	char ch = ' ';
	int x = 40, y = 18,direc = 0;
	int bx[5], by[5];
	setcursor(0);
	draw_ship(x,y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == ' ')
			{
				for (int i = 0; i < 5; i++)
				{
					if (!b[i])
					{
						b[i] = 1;
						bx[i] = x+3;
						by[i] = y-1;
						break;
					}
				}
			}
			if (ch == 'a')
			{
				if(x>0)direc = 1;
			}
			if (ch == 'd')
			{
				if(x<72)direc = 2;
			}
			if (ch == 's')
			{
				direc = 0;
			}
			fflush(stdin);
		}
		for (int i = 0; i < 5; i++)
		{
			if (b[i])
			{
				if (by[i] == 0)
				{
					erase_bullet(bx[i], by[i]);
					b[i] = 0;
				}
				else
				{
					erase_bullet(bx[i], by[i]);
					draw_bullet(bx[i], --by[i]);
				}
			}
		}
		if (direc != 0)
		{
			if (direc == 1)
			{
				erase_ship(x, y);
				draw_ship(--x, y);
			}
			if (direc == 2)
			{
				erase_ship(x, y);
				draw_ship(++x, y);
			}
			if (x == 0 || x == 72) direc = 0;
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

void draw_bullet(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(15, 0);
	printf("o");
}

void erase_bullet(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(0, 0);
	printf(" ");
}