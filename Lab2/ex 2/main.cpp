#include <iostream>
#include <cstring>
#include "NumberList.h"
#include "Header.h"

using namespace std;

int main()
{
	char string[10] = "Stefan";
	char string2[10] = "Ionel";
	NumberList A;
	NumberList B;
	A.setName(string);
	A.setMath(9.5);
	A.setEnglish(5.0);
	A.setHistory(6.8);

	B.setName(string2);
	B.setMath(7.2);
	B.setEnglish(6.3);
	B.setHistory(4.4);

	int f1 = compareName(A, B);
	int f2 = compareMath(A, B);
	int f3 = compareEnglish(A, B);
	int f4 = compareHistory(A, B);
	int f5 = compareAverage(A, B);

	printf("nota la matematica este: %f , la istorie: %f, la engleza: %f\n", A.getMath(), A.getHistory(), A.getEnglish());
	printf("studentul %s are media %f \n\n", A.getName(), A.getAverage());

	if (f1 > 0) printf("studentul %s are nume mai mare decat studentul %s\n", A.getName(), B.getName());
	else if (f1 == 0) printf("studentii au acelasi nume\n");
	else printf("studentul %s are nume mai mic decat studentul %s\n", A.getName(), B.getName());

	if (f2 > 0) printf("studentul %s are nota (%f) la matematica mai mare decat studentul %s (%f)\n", A.getName(),A.getMath(), B.getName(), B.getMath());
	else if (f1 == 0) printf("studentii au aceeasi nota\n");
	else printf("studentul %s are nota (%f) la matematica mai mica decat studentul %s (%f)\n", A.getName(), A.getMath(), B.getName(), B.getMath());
	
	if (f3 > 0) printf("studentul %s are nota (%f) la engleza mai mare decat studentul %s (%f)\n", A.getName(), A.getEnglish(), B.getName(), B.getEnglish());
	else if (f1 == 0) printf("studentii au aceeasi nota\n");
	else printf("studentul %s are nota (%f) la engleza mai mica decat studentul %s (%f)\n", A.getName(), A.getEnglish(), B.getName(), B.getEnglish());

	if (f4 > 0) printf("studentul %s are nota (%f) la istorie mai mare decat studentul %s (%f)\n", A.getName(), A.getHistory(), B.getName(), B.getHistory());
	else if (f1 == 0) printf("studentii au aceeasi nota\n");
	else printf("studentul %s are nota (%f) la istorie mai mica decat studentul %s (%f)\n", A.getName(), A.getHistory(), B.getName(), B.getHistory());

	if (f5 > 0) printf("studentul %s are media (%f) mai mare decat studentul %s (%f)\n", A.getName(), A.getAverage(), B.getName(), B.getAverage());
	else if (f1 == 0) printf("studentii au aceeasi nota\n");
	else printf("studentul %s are media (%f) mai mica decat studentul %s (%f)\n", A.getName(), A.getAverage(), B.getName(), B.getAverage());

}