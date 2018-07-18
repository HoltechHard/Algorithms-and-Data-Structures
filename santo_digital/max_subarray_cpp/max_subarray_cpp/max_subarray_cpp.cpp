// max_subarray_cpp.cpp: define el punto de entrada de la aplicación de consola.

/*PROBLEMA 03: MAXIMUM SUBARRAY SUM
	
	Definimos encontrar:
	- Definimos um subvetor de um vetor 'a' de tamanho n que é um segmento contínuo
	desde a[i] até a[j] para 0<=i<=j<n
	- A soma de um vetor é a soma de seus elementos

	Dado 'n' elementos inteiros para um vetor 'a' e um inteiro 'm', determinar o 
	máximo valor da soma de quaisquer dos subvetores modulo m.
*/

#include "stdafx.h"
#include "iostream"
#define MAX 100

using namespace std;

int sum_vector(int a[MAX], int ini, int fin);
int max_vector(int a[MAX], int n);
int max_subarray_sum(int a[MAX], int n, int m);
void print_vector(int a[MAX], int n);

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *arquivo;
	int k, n, m, a[MAX];
	char url[MAX];

	printf("\n Nome do arquivo: ");
	if(scanf(" %s", url)){}

	arquivo = fopen(url, "r");

	if(arquivo != NULL)
	{
		fscanf(arquivo, "%d", &k);
		fscanf(arquivo, "%d %d", &n, &m);

		for(int i=0;i<n;i++)
		{
			fscanf(arquivo, "%d", &a[i]);
		}

	}else{
		printf("\n Arquivo não existe ... \n");
	}

	fclose(arquivo);

	printf("\n Conjunto A: \n");
	print_vector(a, n);
	printf("\n Max. soma de subarrays: %d \n", max_subarray_sum(a, n, m));

	system("pause");
	return 0;
}

int sum_vector(int a[MAX], int ini, int fin)
{
	int sum = 0;

	for(int i=ini;i<fin;i++)
	{
		sum = sum + a[i];
	}

	return sum;
}

int max_vector(int x[MAX], int n)
{
	int max;
	max = x[0];

	for(int i=1;i<n;i++)
	{
		if(x[i]>max)
			max = x[i];
	}

	return max;
}

int max_subarray_sum(int a[MAX], int n, int m)
{
	int ini, fin, subarray[MAX], index, max;
	ini=0;
	fin=n;
	index=0;

	while(ini<n)
	{
		while(ini<fin)
		{
			subarray[index] = sum_vector(a, ini, fin) % m;
			index = index + 1;
			fin = fin - 1;
		}
		ini = ini + 1;
		fin = n;
	}

	max = max_vector(subarray, index);
	
	return max;
}

void print_vector(int a[MAX], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d \t", a[i]);		
	}

	printf("\n");
}

