#include <iostream>
#include <stdio.h>
using namespace std;

float operator"" _Kelvin(unsigned long long int x) {
    float celsius = 0;
    celsius = x - 273,15;
    return celsius;
}
float operator"" _Fahrenheit(unsigned long long int x) {
    float celsius = 0;
    celsius = (x - 32) / 1,8;
    return celsius;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << a << " " << b << endl;
    return 0;
}