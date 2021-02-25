#include "NumberList.h"
#include <iostream>

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