#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main()
{
	printf("Introduceti propozitie: ");
	char cuvant[200];
	char matrice[200][200] = { 0 };
	int v[200];
	int k = 0;
	while (scanf("%199s", cuvant))
	{
		int lungime = strlen(cuvant);
		strcpy(matrice[k], cuvant);
		v[k] = strlen(cuvant);
		for(int i=0;i<k;i++)
			for (int j = i + 1; j <= k; j++)
			{
				if (v[i] < v[j])
				{
					swap(v[i], v[j]);
					swap(matrice[i], matrice[j]);
				}
			}
		for (int i = 0; i < k; i++)
			for (int j = i + 1; j <= k; j++)
			{
				if (v[i] == v[j])
				{
					if (strcmp(matrice[i], matrice[j]) > 0)
						swap(matrice[i], matrice[j]);
				}
			}
		k++;
	}
	for (int i = 0; i < k; i++)
		printf("%s\n", matrice[i]);
	system("pause");
	return 0;
}