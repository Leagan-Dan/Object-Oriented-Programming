#include <iostream>
#include "Clase.h"
using namespace std;

int main()
{
	Array<int> a(10);
	cout << a[11]<<endl;
	cout << "Insert 3 si 2";
	a.Insert(0, 3);
	a.Insert(1, 2);
	cout<<endl;
	cout <<"Size: "<< a.GetSize()<< endl;
	cout <<"Capacity: "<< a.GetCapacity() << endl;
	cout << "Print: ";
	a.Print();
	cout << endl;
	cout << a.Find(3);
	a.Sort();
	cout << endl;
	cout << "Print: ";
	a.Print();
	cout << endl;
	a += 5;
	cout << "Print: ";
	a.Print();
	cout << endl << "Cautam 2 cu BinarySearch. Se afla pe pozitia: " << a.BinarySearch(2) << endl;
	cout << "Sortare descrescatoare cu functie de comparare: ";
	a.Sort(functieDeComparareDescrescator);
	a.Print();
	cout << endl;
	cout<<a.Find(2,functieDeComparareEgal);
	//cout << endl << "Cautam 3 cu BinarySearch cu functie de comparare: " << a.BinarySearch(2, functieDeComparareEgal) << endl;

	return 0;
}