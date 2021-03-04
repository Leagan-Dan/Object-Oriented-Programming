#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS 
class Canvas
{
    // add private data members
    int x = 6;
    int y = 5;
    char** matrix;
public:
    //Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas

};