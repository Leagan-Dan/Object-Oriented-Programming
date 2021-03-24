#pragma once
class Number
{
private:
	// add data members
	const char* numarul;
	char x[100];
	char v[100];
	int baza;  //verificare daca e intre 2 si 16
	int transformare_numar(char x);
	int transformare_inversa_numar(int x);
	int from_base_to_10();
public:
	Number(const char* value, int base); 
	~Number();

	Number(const Number& n); //copy constructor
	Number(const Number&& n); //move constructor
	Number(const char*);
	
	char operator[](int i);
	friend Number operator+(Number& x, Number& y);
	friend Number operator-(Number& x, Number& y);

	void operator= (const char*);
	void operator= (const Number& n);
	void operator= (int n);


	void operator+= (Number& n);

	void operator-- ();
	void operator-- (int n);

	bool operator> (Number& n);
	bool operator< (Number& n);
	bool operator>= (Number& n);
	bool operator<= (Number& n);
	bool operator== (Number& n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
char* toString(long long);