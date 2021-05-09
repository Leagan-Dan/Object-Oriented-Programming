#pragma once
class NumberList
{
    int numbers[10];
    int count;
    char name[10];
    float math;
    float english;
    float history;

public:
    void setName(char name[10]);
    char* getName();
    void setMath(float math);
    float getMath();
    void setEnglish(float english);
    float getEnglish();
    void setHistory(float history);
    float getHistory();
    float getAverage();

    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector
};

