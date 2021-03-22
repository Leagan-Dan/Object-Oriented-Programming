#include "Number.h"
#include <iostream>
using namespace std;

int main()
{
	Number n1("10110010", 2);
	Number n2("35", 10);
	Number n3("FC", 16);
	printf("n1: "); n1.Print();
	printf("n2: "); n2.Print();
	printf("n3: "); n3.Print();
	printf("Digits Count: %d\n", n1.GetDigitsCount());
	printf("Base: %d\n", n1.GetBase());
	printf("Schimbam n1 din baza 2 in baza 16: ");
	n1.SwitchBase(16);
	n1.Print();
	printf("Schimbam n2 din baza 10 in baza 10: ");
	n2.SwitchBase(10);
	n2.Print();
	printf("Schimbam n3 din baza 16 in baza 10: ");
	n3.SwitchBase(10);
	n3.Print();
	printf("n1[0]: %c\n", n1[0]);
	n1 = n2;
	printf("n1 = n2: ");
	n1.Print();

	Number n4("10", 10);
	Number n5("12", 10);
	printf("operator+ :\n");
	n4 = n4 + n5;
	n4.Print();
	
	Number n6("15", 10);
	Number n7("13", 10);
	printf("operator- :\n");
	n6 = n6 - n7;
	n6.Print();

	--n3;
	n3.Print();

	return 0;
}