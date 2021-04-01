#pragma once
#include <iostream>
using namespace std;
template <class T>
class ExempluTemplate {
	T** v; //vector de pointeri
	int length;

public:
	ExempluTemplate()
	{
		length = 0;
		v = new T * [1];
	}
	void push(T &x)
	{
		length++;
		//resize

		v[length] = &x;
	}
	T& pop()
	{
		length--;
		T aux = *v[length+1];
		v[length + 1] = nullptr;
		return aux;
	}
	void remove(int x)
	{
		delete v[x];

		while (v[x] != nullptr)
		{
			v[x] = v[x + 1];
			x++;
		}
		length--;
	}
	void insert(int i, T &x)
	{
		length++;
		int aux_length = length ;
		//resize
		while (aux_length > i)
		{
			v[aux_length] = v[i];
			aux_length--;
		}
		v[i] = &x;
	}
	void sort()
	{

	}
	T& get(int i)
	{
		return *v[i];
	}
	void set(T &x,int i)
	{
		v[i] = &x;
	}
	int count()
	{
		return length;
	}
	void firstIndexOf()
	{

	}
};