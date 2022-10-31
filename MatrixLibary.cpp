#define _CRT_SECURE_NO_WARNINGS
#include "pch.h" // деректива источника (lib)   
#include <iostream>      
#include "MatrixLibary.h"
using namespace std;

// произведение
int** multiplication(int** ptr_A, int** ptr_B, int size) 
{
	// Выделить память для массива указателей
	int** ptr_C = new int* [size];//со

	// Выделить память для каждого указателя
	for (int i = 0; i < size; i++)
	{
		ptr_C[i] = new int[size];
	}
	//операция
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int h = 0;
			for (int k = 0; k < size; k++)
			{
				h += ptr_A[i][k] * ptr_B[k][j];
			}
			ptr_C[i][j] = h;
		}
	}
	return ptr_C;
}

// сумма
int** addition(int** ptr_A, int** ptr_B, int size) 
{
	int** ptr_C = new int* [size];//со
	for (int i = 0; i < size; i++)
	{
		ptr_C[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ptr_C[i][j] = 0;
			ptr_C[i][j] = ptr_A[i][j] + ptr_B[i][j];
		}
	}
	return ptr_C;
}

// разность
int** subtraction(int** ptr_A, int** ptr_B, int size) 
{
	int** ptr_C = new int* [size];
	for (int i = 0; i < size; i++)
	{
		ptr_C[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ptr_C[i][j] = 0;
			ptr_C[i][j] = ptr_A[i][j] - ptr_B[i][j];
		}
	}
	return ptr_C;
}

//определение обратной матрицы (нуждается в доработке)
int** reverse(int** ptr_A, int size)
{
	int temp;
	int** ptr_B = new int* [size];
	for (int i = 0; i < size; i++) 
	{
		ptr_B[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			ptr_B[i][j] = 0;

			if (i == j)
				ptr_B[i][j] = 1;
		}
	for (int k = 0; k < size; k++)
	{
		temp = ptr_A[k][k];
		for (int j = 0; j < size; j++)
		{
			ptr_A[k][j] /= temp;
			ptr_B[k][j] /= temp;
		}
		for (int i = k + 1; i < size; i++)
		{
			temp = ptr_A[i][k];
			for (int j = 0; j < size; j++)
			{
				ptr_A[i][j] -= ptr_A[k][j] * temp;
				ptr_B[i][j] -= ptr_B[k][j] * temp;
			}
		}
	}
	for (int k = size - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = ptr_A[i][k];
			for (int j = 0; j < size; j++)
			{
				ptr_A[i][j] -= ptr_A[k][j] * temp;
				ptr_B[i][j] -= ptr_B[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) 
			ptr_A[i][j] = ptr_B[i][j];

	return ptr_A;
}
//транспортирование
int** transpose(int** ptr_A, int size) 
{
	int tmp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			tmp = ptr_A[i][j];
			ptr_A[i][j] = ptr_A[j][i];
			ptr_A[j][i] = tmp;
		}
	}
	return ptr_A;
}

/*
// НЕ НУЖНО !!!
int** initMatrix(matrix* m, int size)  // создание матрицы
{
	int l = 0;
	//int** ptr = (int**)malloc(size * sizeof(int*));

	// Выделить память для массива указателей
	int** ptr =  new int* [size];//со

	 // Выделить память для каждого указателя
	for (int i = 0; i < size; i++)
	{
		ptr[i] = new int[size];
		//ptr[a] = (int*)malloc(size * sizeof(int));
	}

	//printf("elements:\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//while ((scanf("%lf", &l) != 1) || (getchar() != '\n'))
			//{
			//	printf("Error, try again\n");
			//	while (getchar() != '\n');
			//}
			cin >> l;
			ptr[i][j] = l;
		}
	}
	m->razmer = size;
	m->Mat_A = ptr;

	return(ptr);
	free(ptr);
}*/

/*
// НЕ НКЖНО!!!
void deletMatrix(int** ptr, int size)    // уничтожение
{
	for (int i = 0; i < size; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}*/
/*
int** stepen(int** ptr_A, int size, int n) //  степень
{

	if (n < 0)  return NULL;
	else if (n == 0)
	{
		int** ptr_C = (int**)malloc(size * sizeof(int*));

		for (int a = 0; a < size; a++)
		{
			ptr_C[a] = (int*)malloc(size * sizeof(int));

		}
		for (int i = 0; i < size; i++)

			for (int j = 0; j < size; j++)

				if (i == j) ptr_C[i][j] = 1;

				else ptr_C[i][j] = 0;


		return ptr_C;
	}
	else if (n == 1) return ptr_A;


	int** ptr_G = composition(ptr_A, ptr_A, size);
	for (int i = 2; i < n; i++) {
		ptr_G = composition(ptr_G, ptr_A, size);
	}
	return ptr_G;

	free(ptr_G);

}*/
