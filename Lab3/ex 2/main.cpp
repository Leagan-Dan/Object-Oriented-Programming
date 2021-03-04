#include <iostream>
#include <cstring>
#include "Canvas.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main()
{
	Canvas A;
	int x;
	A.DrawCircle(3, 4, 5, '*');
	A.FillCircle(3, 4, 5, '*');
	A.DrawRect(2, 2, 8, 4, '*');
	cout << endl;
	A.FillRect(2, 2, 8, 4, '*');
	A.SetPoint(3, 3, '*');
	A.DrawLine(2, 2, 2, 6,'*');
	A.Print();
	A.Clear();
}