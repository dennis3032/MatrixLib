#define _CRT_SECURE_NO_WARNINGS
#include "pch.h" // деректива источника (lib)
#include <iostream>      
#include "MatrixLibary.h"
using namespace std;

// умножение
int** multiplication(int** ptr_A, int** ptr_B, int size) 
{
	// Выделить память для массива указателей
	int** ptr_C = new int* [size];//ñî

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
	int** ptr_C = new int* [size];//ñî
	for (int i = 0; i < size; i++)
	{
		ptr_C[i] = new int[size];
	}
        //операция
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
        // операция
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
//определение обратной матрицы(*В РАЗРАБОТКЕ*)
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

