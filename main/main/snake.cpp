#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;
int sl = 7;
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_duoi();
void ve_tuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
int main()
{
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	while (gameover == false)
	{
		xoa_du_lieu_cu(toadox, toadoy);
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0)
				{
					check = 1;
				}
				else if (kitu == 80 && check != 1)
					check = 0;
			}
			else if (kitu == 77 && check != 3)
			{
				check = 2;
			}
			else if (kitu == 75 && check != 2)
			{
				check = 3;
			}
		}
	}
	if (check == 0)
	{
		y++;
	}
	else if (check == 1)
	{
		y--;
	}
	else if (check == 2)
	{
		x++;
	}
	else if (check == 3)
	{
		x--;
	}
	//conflict
	xu_ly_ran(toadox, toadoy, x, y, xqua, yqua)
		gameover = kt_ran(toadox, toadoy);
	Sleep(150);
}
_getch();
return 0;
}
void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 10, y = 26;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void ve_tuong_phai()
{
	int x = 100, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong()
{
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();
	SetColor(7);
}