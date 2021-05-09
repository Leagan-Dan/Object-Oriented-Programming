#include <iostream>
#include <cstring>
#include "Math.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main()
{
	Math A;
	int x;
	x = A.Add(4, 6);
	cout << "suma a doua numere: " << x << endl;
	x = A.Add(4, 6, 7);
	cout << "suma a 3 numere: " << x << endl;
	x = A.Add(2.3, 4.5);
	cout << "suma a doua numere double: " << x << endl;
	x = A.Add(2.3, 4.5, 6.1);
	cout << "suma a 3 numere double: " << x << endl;
	x = A.Mul(2, 3);
	cout << "produsul a 2 numere: " << x << endl;
	x = A.Mul(2, 3, 4);
	cout << "produsul a 3 numere: " << x << endl;
	x = A.Mul(2.3, 1.4);
	cout << "produsul a 2 numere double: " << x << endl;
	x = A.Mul(2.3, 1.4, 5.2);
	cout << "produsul a 3 numere double: " << x << endl;
	x = A.Add(4, 1, 2, 5, 7);
	cout << "suma a celor 4 numere: " << x << endl;
	char* y=nullptr;
	y = A.Add("ana", "mere");
	cout << "concatenarea ana + mere: " << y << endl;

}