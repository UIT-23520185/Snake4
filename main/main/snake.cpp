void khoi_tao_ran(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "O";
		}
		else
		{
			cout << "o";
		}
	}
}
void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
//conflict
void xu_ly_ran(int toadox[], int toadoy[], int& xqua, int& yqua)
{
	int x;
	int y,
		them(toadox, x);
	them(toadoy, y);

	if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false)
	{

		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);

	}
	else
	{
		sl--;
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	ve_ran(toadox, toadoy);
}
void them(int a[], int x)
{
	for (int i = sl; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
//conflict
void xoa(int a[])
{
	int vt
		for (int i = vt; i < sl; i++)
		{
			a[i] = a[i + 1];
		}
	sl--;
}
// conflict
bool kt_ran_cham_tuong(int x0, int y0)
{
	if (y0 == 1 && (x0 >= 10 && x0 <= 90))
	{
		return true;
	else if (y0 == 20 && (x0 >= 10 && x0 <= 90))
	{
		return true;
	}
	else if (x0 == 90 && (y0 >= 1 && y0 <= 20))
	{
		return true;
	}
	else if (x0 == 10 && (y0 >= 1 && y0 <= 20))
	{
		return true;
	}
	return false;
	}
	bool kt_ran_cham_duoi(int toadox[], int toadoy[])
	{
		for (int i = 1; i < sl; i++)
		{
			if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
			{
				return true;
			}
		}
		return false;
	}
	bool kt_ran(int toadox[], int toadoy[])
	{
		bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
		bool kt2 = kt_ran_cham_tuong(toadox[0], toadoy[0]);
		if (kt1 == true || kt2 == true)
		{
			return true;
		}
		return false;
	}
	//conflict
	void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[])
	{
		do
		{
			xqua = rand() % (89 - 11 + 1) + 11;
			yqua = rand() % (19 - 2 + 1) + 2;
		} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
		int i = rand() % (15 - 1 + 1) + 1;
		SetColor(i);
		gotoXY(xqua, yqua);
		cout << "$";
		SetColor(7);
	}
	bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
	{
		for (int i = 0; i < sl; i++)
		{
			if ((xqua == toadox[i]) && (yqua == toadoy[i]))
			{
				return true;
			}
		}
		return false;
	}
	bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0)
	{
		if ((x0 == xqua) && (y0 == yqua))
		{
			return true;
		}
		return false;
	}