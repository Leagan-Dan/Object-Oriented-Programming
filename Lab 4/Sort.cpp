#include "Sort.h"
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <time.h>

using namespace std;
void Sort::quickSort(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);

		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}
int Sort::partition(int low, int high) {

	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (array[j] < pivot) {
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[high]);
	return (i + 1);
}
void Sort::reverseArray() {
	for (int i = 0; i < length / 2; i++) {
		swap(array[i], array[length - i - 1]);
	}
}



Sort::Sort(int nr_elements, int min, int max)
{
	time_t t;
	srand((unsigned)time(&t));
	length = nr_elements;
	array = new int [length];
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % (max-min+1) + min;
	}
}
Sort::Sort()
{
	length = 5;
	array = new int[5]{ 6,2,4,3,8 };
}
Sort::Sort(int* v,int nr_elements)
{
	this->length = nr_elements;
	array = v;
}
Sort::Sort(int nr_elements, ...)
{
	this->length = nr_elements;
	array = new int[length];
	va_list lista;
	va_start(lista, nr_elements);
	for (int i = 0; i < length; i++)
	{
		int val = va_arg(lista, int);
		array[i] = val;
	}
	va_end(lista);
}
Sort::Sort(char* s)
{
	length = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ',')
			length++;
	}
	length++;
	array = new int[length];

	int nr = 0;
	int i = 0;
	for (int l = 0; s[l] != '\0'; l++) {
		if (s[l] == ',') {
			array[i++] = nr;
			nr = 0;
			continue;
		}
		nr = nr * 10 + (s[l] - '0');
	}
	array[i] = nr;
	i++;
}



void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->length; i++) {
		int c = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > c) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = c;
	}

	if (ascendent == false) {
		reverseArray();
	}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(0, length - 1);

	if (ascendent == false) {
		reverseArray();
	}
}
void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}

	if (ascendent == false) {
		reverseArray();
	}
}



void Sort::Print()
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i]<<" ";
	}
	cout << endl;
}
int Sort::GetElementsCount()
{
	return length;
}
int Sort::GetElementFromIndex(int index)
{
	if (index < length && index >= 0)
	return array[index];
}