#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int functie(char myString[200])
{
	int result = 0;
	int lungime = strlen(myString);
	for (int i=0; i<lungime - 1; i++)
	result = result * 10 + ((int)myString[i] - 48);
	return result;
}
int main()
{
	
	FILE* fp;
	if (fopen_s(&fp, "ini.txt", "r") != 0) //daca e 0 am deschis fisierul
	{
		printf("%s", "Eroare. Nu am putut deschide fisierul\n");
	}
	else
	{
		printf("%s", "Am deschis fisierul\n\n");
	}

	char myString[200];
	int rez = 0;
	while (fgets(myString, 200, fp))
	{
		printf("Am citit din fisier: %s\n", myString);
		rez = rez + functie(myString);
	}
	printf("Suma ceruta este: %d\n", rez);
	system("pause");
	return 0;
}