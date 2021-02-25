#include <iostream>
#include <cstring>
#include "NumberList.h"
#include "Header.h"

int compareName(NumberList A, NumberList B)
{
	return(strcmp(A.getName(), B.getName()));
}
int compareMath(NumberList A, NumberList B)
{
	if (A.getMath() == B.getMath())
		return 0;
	else if (A.getMath() > B.getMath())
		return 1;
	else
		return -1;
}
int compareEnglish(NumberList A, NumberList B)
{
	if (A.getEnglish() == B.getEnglish())
		return 0;
	else if (A.getEnglish() > B.getEnglish())
		return 1;
	else
		return -1;
}
int compareHistory(NumberList A, NumberList B)
{
	if (A.getHistory() == B.getHistory())
		return 0;
	else if (A.getHistory() > B.getHistory())
		return 1;
	else
		return -1;
}
int compareAverage(NumberList A, NumberList B)
{
	if (A.getAverage() == B.getAverage())
		return 0;
	else if (A.getAverage() > B.getAverage())
		return 1;
	else
		return -1;
}