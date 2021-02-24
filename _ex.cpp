#include <iostream>

void f2(int ** & a, size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

void f1(int ** & a, size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			a[i][j] += i + j;
		}
	}
	
	f2(a, m, n);
}

int main(int argc, char const *argv[])
{
	int M = 4, N = 4;
	int ** matrix = new int * [M];
	for (size_t i = 0; i < M; i++)
	{
		matrix[i] = new int [N];
		for (size_t j = 0; j < N; j++)
		{
			matrix[i][j] = i + j;
		}
	}

	f2(matrix, M, N);

	f1(matrix, N, M);

	for (size_t i = 0; i < M; i++)
	{
		delete [] matrix[i];
	}
	
	delete [] matrix;

	return 0;
}
