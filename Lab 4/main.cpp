#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
	int v[4] = { 5,3,7,4 };
	char s[20] = "10,15,8,20";
	Sort A = Sort(5, 10, 100);
	Sort B = Sort(v, 4);
	Sort C = Sort(5,7,2,6,1,3);
	Sort D = Sort(s);
	Sort E = Sort();
	A.InsertSort(false);
	A.Print();
	B.QuickSort(true);
	B.Print();
	D.BubbleSort(false);
	D.Print();
	cout << "(vector nesortat) "; 
	C.Print();
	cout << "elementul de pe indexul 2 din C: " << C.GetElementFromIndex(2) << endl;
	cout << "numarul de elemente al vectorului C: " << C.GetElementsCount() << endl;
	E.BubbleSort(true);
	E.Print();
}