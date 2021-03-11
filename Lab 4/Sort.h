#pragma once
class Sort
{
private:
    int* array;
    int length;
    // add data members
    void reverseArray();
    void quickSort(int, int);
    int partition(int, int);
public:
    // add constuctors
    Sort();
    Sort(int nr_elements, int min, int max);
    Sort(int* v,int nr_elements);
    Sort(int nr_elements , ...);
    Sort(char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};