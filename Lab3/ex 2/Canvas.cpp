#include "Canvas.h"
#include <cstring>
#include <stdarg.h>
#include <malloc.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS 
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{

}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int nr_linii = x;
	int nr_coloane = y;
	char** matrix = (char**)(malloc(nr_linii * sizeof(char*)));
	for (int i = 0; i < nr_linii; i++)
		matrix[i] = (char*)(malloc(nr_coloane * sizeof(char)));




	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (i == 0 || j == 0 || i == x-1 || j == y-1)
				matrix[i][j] = ch;
			else
				matrix[i][j] = ' ';
	


	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << "\n";
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int nr_linii = x;
	int nr_coloane = y;
	char** matrix = (char**)(malloc(nr_linii * sizeof(char*)));
	for (int i = 0; i < nr_linii; i++)
		matrix[i] = (char*)(malloc(nr_coloane * sizeof(char)));




	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			matrix[i][j] = ch;



	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << "\n";
	}
}
void Canvas::SetPoint(int x, int y, char ch)
{

}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{

}
void Canvas::Print() // shows what was printed
{
	
	
}
void Canvas::Clear() // clears the canvas
{

}