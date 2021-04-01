#include <iostream>
#include "Templates.h"

using namespace std;

int main()
{
	ExempluTemplate<int> v;
	int a = 5;
	v.push(a);
	cout << v.get(0)<<endl;
	a = 3;
	v.push(a);
	cout << v.get(1)<<endl;
	cout<< v.pop()<<endl;

	return 0;
}