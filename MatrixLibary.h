#pragma once

#ifdef MATRIXLIBARY_EXPORTS
#define MATRIXLIBARY_API __declspec(dllexport) //модификатор обьявления ф-ий
#else
#define MATRIXLIBARY_API __declspec(dllimport)
#endif

//extern "C" указывает, что функция определена в другом месте и использует соглашение о вызовах на языке C.

extern "C" MATRIXLIBARY_API struct matrix
{
	int** Mat_A;

	int razmer;
};

//extern "C" MATRIXLIBARY_API int** initMatrix(matrix * m, int size);

//extern "C" MATRIXLIBARY_API void deletMatrix(int** ptr, int size);

extern "C" MATRIXLIBARY_API int** multiplication(int** ptr_A, int** ptr_B, int size);

extern "C" MATRIXLIBARY_API int** addition(int** ptr_A, int** ptr_B, int size);

extern "C" MATRIXLIBARY_API int** subtraction(int** ptr_A, int** ptr_B, int size);

//extern "C" MATRIXLIBARY_API int** stepen(int** ptr_A, int size, int n);

extern "C" MATRIXLIBARY_API int** reverse(int** ptr_A, int size);

extern "C" MATRIXLIBARY_API int** transpose(int** ptr_A, int size);




