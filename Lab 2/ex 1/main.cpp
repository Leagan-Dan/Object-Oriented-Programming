#include <iostream>
#include <cstring>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList A;
	A.Init();
	A.Add(4);
	A.Add(7);
	A.Add(3);
	A.Print();
	A.Sort();
	A.Print();
}