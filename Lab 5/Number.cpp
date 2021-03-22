#include "Number.h"
#include <cstring>
#include <stdio.h>
#include <iostream>
Number::Number(const char* value, int base)
{
	v[100] = { 0 };
	numarul = value;
	baza = base;
}
Number::~Number()
{
	baza = 0;
	numarul = NULL;
}
int Number::from_base_to_10()
{
	int sum = 0;
	int p = 0;
	int lungimea = strlen(numarul);
	for (int i = lungimea - 1; i >= 0; i--)
	{
		int aux = transformare_numar(numarul[i]);
		sum = sum + aux * pow(baza, p);
		int q = aux * pow(baza, p);
		p++;
	}
	return sum;
}
int Number::transformare_numar(char x)
{
	if (x == 'A')
		return 10;
	if (x == 'B')
		return 11;
	if (x == 'C')
		return 12;
	if (x == 'D')
		return 13;
	if (x == 'E')
		return 14;
	if (x == 'F')
		return 15;
	return x - '0';
}
int Number::transformare_inversa_numar(int x)
{
	if (x >= 0 && x <= 9)
		return char(x + '0');
	else
		return char(x - 10 + 'A');
}
void Number::SwitchBase(int newBase)
{
	int sum = 0;
		sum = from_base_to_10();
	//acum am in sum un nr in baza 10
	
	int i = 0;
	while (sum > 0)
	{
		v[i++] = transformare_inversa_numar(sum % newBase);
		sum = sum / newBase;
	}


	v[i] = '\0';
	int len = strlen(v);
	int j = 0;
	for (j = 0; j < len / 2; j++)
	{
		char temp = v[j];
		v[j] = v[len - j - 1];
		v[len - j - 1] = temp;
	}
	baza = newBase;
	this->numarul = v;

}
void Number::Print()
{
	printf("%s\n", numarul);
}
int  Number::GetDigitsCount()
{
	int count = 0;
	for (int i = 0; i < strlen(numarul); i++)
		count++;
	return count;
}
int  Number::GetBase()
{
	if (baza >= 2 && baza <= 16)
		return baza;
	else
		return -1;
}
Number::Number(const char* n)
{
	this->numarul = n;
}
Number::Number(const Number& n)
{
	this->numarul = n.numarul;
}
Number::Number(const Number&& n)
{

	this->numarul = n.numarul;
}
void Number::operator=(const char* s) {
	Number nr(s, 10);
	*this = nr;
}

void Number::operator=(const Number& n) {
	this->baza = n.baza;
	this->numarul = n.numarul;
}
void Number::operator=(int n) {
	Number nr(toString(n), 10);
	nr.SwitchBase(baza);
	*this = nr;
}

Number operator+(Number& x, Number& y)
{
	int baza_mai_mare;
	Number a = x;
	Number b = y;
	a.baza = x.baza;
	b.baza = y.baza;
	int k = x.GetBase();
	if (a.GetBase() > b.GetBase())
		 baza_mai_mare = a.GetBase();
	else
		 baza_mai_mare = b.GetBase();

	
	int sum;
	sum = a.from_base_to_10();
	sum = sum + b.from_base_to_10();

	
	char* c = toString(sum);
	Number newN(c, 10);

	/*
	newN.Print();
	int q= newN.GetBase();
	printf("q: %d\n", q);

	//newN.SwitchBase(10);
	//nu-mi merge schimbarea de baza, cand o apelez aici

	int p = newN.GetBase();
	printf("p: %d\n", p);
	newN.Print();
	*/

	return newN;
}
Number operator-(Number& x, Number& y)
{
	int baza_mai_mare;
	Number a = x;
	Number b = y;
	a.baza = x.baza;
	b.baza = y.baza;
	int k = x.GetBase();
	if (a.GetBase() > b.GetBase())
		baza_mai_mare = a.GetBase();
	else
		baza_mai_mare = b.GetBase();


	int dif;
	dif = a.from_base_to_10();
	dif = dif - b.from_base_to_10();

	
	char* c = toString(dif);
	Number newN(c, 10);
	
	return newN;
}
void Number::operator--()
{
	numarul++;
}

bool Number::operator>(Number& n)
{
	int x = from_base_to_10();
	int y = n.from_base_to_10();

	return x > y;
}
char Number::operator[](int i) {
	return numarul[i];
}
char* toString(long long n) {
	char* s = new char[50];
	int i = 0;
	bool b = false;
	if (n < 0) {
		n = -n;
		b = true;
	}
	while (n != 0) {
		int d = n % 10;
		s[i++] = '0' + d;
		n /= 10;
	}
	if (b) {
		s[i++] = '-';
	}
	s[i] = '\0';
	for (int l = 0; l < i / 2; l++) {
		char aux = s[l];
		s[l] = s[i - l - 1];
		s[i - l - 1] = aux;
	}
	return s;
}