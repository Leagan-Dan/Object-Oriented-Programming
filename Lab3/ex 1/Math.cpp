#include "Math.h"
#include <cstring>
#include <stdarg.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS 

int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y , int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...) // sums up a list of integers
{
	int temp;
	int sum=0;
	va_list lista;
	va_start(lista, count);
	for (int i = 0; i < count; i++)
	{
		temp = va_arg(lista, int);
		sum += temp;
	}
	va_end(lista);
	return sum;
}
char* Math:: Add(const char* x, const char* y)
{
	if (x == nullptr || y == nullptr)
		return nullptr;
	else
	{
		char* z = (char*) malloc (1 + strlen(x) + strlen(y));
		int sizeToRealloc;
		memset(z, 0, strlen(x) + strlen(y) + 1);
		memcpy(z, x, strlen(x));
		memcpy(z + strlen(x), y, strlen(y));
		return z;
	}
}