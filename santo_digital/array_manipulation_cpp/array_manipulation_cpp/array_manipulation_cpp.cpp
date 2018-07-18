// array_manipulation_cpp.cpp: define el punto de entrada de la aplicación de consola.

/*PROBLEMA 04: ARRAY MANIPULATION

	Iniciando com um vetor unidimensional de zeros e uma lista de operações, 
	para cada operação adicionar um valor para cada elemento do vetor entre ou
	incluido entre os índices. De todos os resultados das operações, retornar o 
	máximo valor do vetor obtido
*/

#include "stdafx.h"
#include "iostream"
#define MAX 100

using namespace std;

int array_manipulation(int n, int m, int queries[MAX][MAX]);
void print_matrix(int x[MAX][MAX], int m);

int _tmain(int argc, _TCHAR* argv[])
{	
	FILE *arquivo;
	char url[MAX];
	int n, m, queries[MAX][MAX], max;	

	printf("\n Nome do arquivo: ");
	if(scanf(" %s", url)){}

	arquivo = fopen(url, "r");

	if(arquivo!= NULL)
	{
		fscanf(arquivo, "%d %d", &n, &m);

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<3;j++)
			{
				fscanf(arquivo, "%d", &queries[i][j]);
			}
		}

	}else{
		printf("\n O arquivo nao existe \n");
	}

	fclose(arquivo);

	printf("\n Matriz de queries \n");	
	print_matrix(queries, m);

	max = array_manipulation(n, m, queries);
	printf("\n Max. valor operacoes: %d \n \n", max);	

	system("pause");
	return 0;
}

int array_manipulation(int n, int m, int queries[MAX][MAX])
{
	int x[MAX], max;

	for(int i=1;i<=n;i++)
	{
		x[i] = 0;
	}

	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j>=queries[i][0] && j<=queries[i][1])
			{
				x[j] = x[j] + queries[i][2];
			}
		}
	}

	max = x[1];

	for(int i=2;i<=n;i++)
	{
		if(x[i]>max)
			max = x[i];
	}

	return max;
}

void print_matrix(int x[MAX][MAX], int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d \t", x[i][j]);			
		}
		printf("\n");
	}
}