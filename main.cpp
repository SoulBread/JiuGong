#include "game.h"
#include <iostream>
using namespace std;
void main()
{
	game X;
	int choose;
	string str,str1;
	X.t2 = 0;
	cout << "---------------------�Ź���Ϸ---------------------" << endl;
	cout << "                    1.��Ϸѡ��" << endl;
	cout << "                    2.�˳���Ϸ" << endl;
	cout << "--------------------------------------------------" << endl << endl;
	cin >> choose;
	if (choose == 1)
	{
		X.select();
		cout << "Ŀ��:"<<endl;
		X.start();
		X.display();
		X.pailie();
		X.display();
		bool flag;
		while (1)
		{
			cout << "w.��\ts.��\ta.��\td.��" << endl;
			cout << "e.������һ��\tf.�˳�" << endl << endl;
			cout << "���������:";
			cin >> str;
			if (str == "w")
				str1 = "��";
			if (str == "s")
				str1 = "��";
			if (str == "a")
				str1 = "��";
			if (str == "d")
				str1 = "��";
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
				cout << "�ɹ�!" << endl;
				break;
			}
		}
		int choose1;
		cout << "�Ƿ���Ҫ��ʾ�ƶ�����?" << endl;
		cout << "1.��Ҫ\t2.����Ҫ" << endl;
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