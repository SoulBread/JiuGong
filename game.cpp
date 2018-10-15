#include "game.h"
game::game(){}
game::~game(){}
void game::start()
{
	int a;
	for (a = 0; a < n; a++)
		A[a] = a + 1;
	A[n-1] = 0;
	for (a = 0; a < n; a++)
		C[a] = A[a];
}
void game::display()
{
	int o1;
	string len;
	if (n == 9)
		o1 = 19;
	if (n == 16)
		o1 = 28;
	if (n == 25)
		o1 = 36;
	len = "-";
	int o = 1;
	while (1)
	{
		len += "-";
		o++;
		if (o == o1)
			break;
	}
	cout << len<< endl;
	for (int a = 0; a < n; a++)
	{
		cout << A[a] << "\t";
		for (int aa = 1; aa <= (int)sqrt(n); aa++)
		{
			if (a == aa*(int)sqrt(n) - 1)
			{
				cout << endl <<len << endl;
				break;
			}
		}
	}
}
void game::pailie()
{
	int c1 = n,t=0;
	int cc;
	while (t < n) 
	{
		srand((int)time(NULL));
		cc = rand() % c1;
		for (int i = 0; i < c1; i++)
		{
			if (i == cc)
			{
				B[t] = A[i];
				for (int j = i; j < c1; j++)
				{
					A[j] = A[j + 1];
				}
				break;
			}
		}
		t++;
		c1--;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
		A[i] = B[i];
	for (int i = 0; i < n; i++)
		D[i] = A[i];
}
void game::change(string str)
{

	int t, t1;
	t1 = (int)sqrt(n);
	for (int i = 0; i < n; i++)
	{
		if (A[i]==0)
		{
			if (str == "上")
			{
				t = A[i - t1];
			    A[i - t1] = A[i];
				A[i] = t;
			}
			if (str == "下")
			{
				t = A[i + t1];
				A[i + t1] = A[i];
				A[i] = t;
			}
			if (str == "左")
			{
				t = A[i - 1];
				A[i - 1] = A[i];
				A[i] = t;
			}
			if (str == "右")
			{
				t = A[i + 1];
				A[i + 1] = A[i];
				A[i] = t;
			}
			break;
		}
	}
}
void game::select()
{
	int s;
	cout << "请选择游戏的难度:" << endl;
	cout << "1.简单(3x3)" << endl;
	cout << "2.一般(4x4)" << endl;
	cout << "3.困难(5x5)" << endl;
	cin >> s;
	if (s == 1)
		n = 9;
	if (s == 2)
		n = 16;
	if (s == 3)
		n = 25;
}
string game::fanhui(string str)
{
	string str1;
	if (str == "上")
		str1 = "下";
	if (str == "下")
		str1 = "上";
	if (str == "左")
		str1 = "右";
	if (str == "右")
		str1 = "左";
	return str1;
}
void game::yidong()
{
	cout << endl << endl << "移动过程演示:" << endl;
	start();
	int time1;
	cout << "请输入每多少秒显示一次:";
	cin >> time1;
	for (int i = 0; i < n; i++)
		A[i] = D[i];
	display();
	int l = 0;
	srand((int)time(NULL));
	begin = clock();
	while (l < t2)
	{
		end = clock();
		q = (int)(end - begin) / 1000;
		if (q == time1)
		{
			change(S[l]);
			display();
			l++;
			cout << endl;
			begin = clock();
		}
	}
}