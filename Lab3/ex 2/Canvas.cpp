#include "Canvas.h"
#include <cstring>
#include <stdarg.h>
#include <malloc.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS 
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	int nr_linii = width;
	int nr_coloane = height;
	matrix = (char**)(malloc(nr_linii * sizeof(char*)));
	for (int i = 0; i < nr_linii; i++)
		matrix[i] = (char*)(malloc(nr_coloane * sizeof(char)));

}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * (ray - 1) && ((i - x) * (i - x) + (j - y) * (j - y)) >= ray * (ray - 2))
				matrix[i][j] = '*';
			else
				matrix[i][j] = ' ';

}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * (ray - 1))
				matrix[i][j] = '*';
			else
				matrix[i][j] = ' ';
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (i == top || j == left || i == bottom || j == right)
			{
				matrix[i][j] = ch;
			}
			else
				matrix[i][j] = ' ';
			if (i< top || i>bottom || j<left || j>right)
				matrix[i][j] = ' ';
		}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			matrix[i][j] = ch;
			if (i< top || i>bottom || j<left || j>right)
				matrix[i][j] = ' ';
		}
}
void Canvas::SetPoint(int x, int y, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i == x && j == y)
				matrix[i][j] = '*';
			else
				matrix[i][j] = ' ';
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (x1 == x2)
	{
		for (int i = y1; i <= y2; ++i)
		{
			matrix[x1][i] = ch;
		}
	}
	else
	{
		float dx = x2 - x1;
		float dy = y2 - y1;
		float panta = abs(dy / dx);
		float e = 0.0;
		int y = y1;
		for (int x = x1; x <= x2; ++x)
		{
			matrix[x][y] = ch;
			e = e + panta;
			if (e >= 0.5)
			{
				y = y + abs(dy);
				e = e - 1.0;
			}
		}
	}
}
void Canvas::Print() // shows what was printed
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << "\n";
	}
}
void Canvas::Clear() // clears the canvas
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}