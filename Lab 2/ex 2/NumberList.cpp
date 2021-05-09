#include "NumberList.h"
#include <cstring>
#include <iostream>

using namespace std;
void NumberList::setName(char name[10])
{
	strcpy_s(this->name, name);
}
char* NumberList::getName()
{
	return this->name;
}
void NumberList::setMath(float math)
{
	if(math>=1 && math<=10)
	this->math = math;
}
float NumberList::getMath()
{
	return this->math;
}
void NumberList::setEnglish(float english)
{
	if (english >= 1 && english<= 10)
	this->english = english;
}
float NumberList::getEnglish()
{
	return this->english;
}
void NumberList::setHistory(float history)
{
	if (history >= 1 && history <= 10)
	this->history = history;
}
float NumberList::getHistory()
{
	return this->history;
}
float NumberList::getAverage()
{
	if(this->math && this->english && this->history)
	return (this->math + this->english + this->history) / 3;
}
void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10)
		return false;
	else
	{
		this->numbers[this->count] = x;
		this->count++;
	}
	return true;
}
void NumberList::Sort()
{
	for (int i = 0; i < this->count - 1; i++)
		for (int j = i + 1; j < this->count; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}
void NumberList::Print()
{
	printf("vectorul meu are numerele: ");
	for (int i = 0; i < this->count; i++)
		printf("%d, ", this->numbers[i]);
	printf("\n");
}