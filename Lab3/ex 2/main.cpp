#include <iostream>
#include <cstring>
#include "Canvas.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main()
{
	Canvas A(13, 13);
	A.Clear();
	A.DrawCircle(5, 5, 6, '*');
	A.Print();
	A.Clear();
	A.FillCircle(4, 4, 3, '*');
	A.Print();
	A.Clear();
	A.DrawRect(2, 2, 9, 5, '*');
	A.Print();
	A.Clear();
	A.FillRect(1, 1, 5, 8, '*');
	A.Print();
	A.Clear();
	A.SetPoint(1, 1, '*');
	A.Print();
	A.Clear();
	A.DrawLine(2, 2, 4, 4, '*');
	A.Print();
	A.Clear();
}