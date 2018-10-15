#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cmath>
#define m 1000
using namespace std;
class game
{
public:
	int n,q,t2;
	int A[m], B[m], C[m],D[m];
	string S[m];
	double begin, end;
	game();
	~game();
	void start();
	void display();
	void pailie();
	void change(string str);
	void select();
	string fanhui(string str);
	void yidong();
};

