#include "game.h"
#include <iostream>
using namespace std;
void main()
{
	game X;
	int choose;
	string str,str1;
	X.t2 = 0;
	cout << "---------------------九宫游戏---------------------" << endl;
	cout << "                    1.游戏选择" << endl;
	cout << "                    2.退出游戏" << endl;
	cout << "--------------------------------------------------" << endl << endl;
	cin >> choose;
	if (choose == 1)
	{
		X.select();
		cout << "目标:"<<endl;
		X.start();
		X.display();
		X.pailie();
		X.display();
		bool flag;
		while (1)
		{
			cout << "w.上\ts.下\ta.左\td.右" << endl;
			cout << "e.返回上一步\tf.退出" << endl << endl;
			cout << "请输入操作:";
			cin >> str;
			if (str == "w")
				str1 = "上";
			if (str == "s")
				str1 = "下";
			if (str == "a")
				str1 = "左";
			if (str == "d")
				str1 = "右";
			if (str == "e")
				str1 = X.fanhui(str1);
			if (str == "f")
				break;
			X.change(str1);
			X.S[X.t2] = str1;
			X.t2++;
			X.display();
			for (int i = 0; i < X.n; i++)
			{
				flag = true;
				if (X.A[i] != X.C[i])
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				cout << "成功!" << endl;
				break;
			}
		}
		int choose1;
		cout << "是否需要演示移动过程?" << endl;
		cout << "1.需要\t2.不需要" << endl;
		cin >> choose1;
		if (choose1 == 1)
		{
			X.yidong();
		}
		else
			return;
	}
	else
		return;
}