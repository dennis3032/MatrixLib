#pragma once

#ifdef MATRIXLIBARY_EXPORTS
#define MATRIXLIBARY_API __declspec(dllexport) //модификатор обьявления ф-ий
#else
#define MATRIXLIBARY_API __declspec(dllimport)
#endif


extern "C" MATRIXLIBARY_API struct matrix
{
	int** Mat_A;

	int razmer;
};


extern "C" MATRIXLIBARY_API int** multiplication(int** ptr_A, int** ptr_B, int size);

extern "C" MATRIXLIBARY_API int** addition(int** ptr_A, int** ptr_B, int size);

extern "C" MATRIXLIBARY_API int** subtraction(int** ptr_A, int** ptr_B, int size)

extern "C" MATRIXLIBARY_API int** reverse(int** ptr_A, int size);

extern "C" MATRIXLIBARY_API int** transpose(int** ptr_A, int size);




