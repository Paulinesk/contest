#include <iostream>
#include <ctime>

int **Create(size_t n, size_t m) // создание матрицы
{
	int **M = new int *[n];
	for (size_t i = 0; i < n; ++i)
	{
		M[i] = new int[m];
	}
	return M;
}
void Input(int **M, size_t n, size_t m) // ввод матрицы
{
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			std::cout << "M[" << i << "][" << j << "] = ";
			std::cin >> M[i][j];
		}
	}
}
void FillRandomNumbers(int **matrix, const size_t rows, const size_t columns) // заполнение случайными числами
{
	srand((unsigned int)time(0)); //

	for (size_t row = 0; row < rows; row++)
		for (size_t column = 0; column < columns; column++)
			matrix[row][column] = rand() % 99 + 1;
}
void Print(int ** M, size_t n, size_t m) {
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			std::cout << M[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void Process(int ** M, int *Sum, size_t n, size_t m) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			Sum+= M[i][i];
		}
	}
}
void Delete(int ** M, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		delete[] M[i];
	}
	delete[] M;
}
int main()
{
	setlocale( LC_ALL, "Rus" );

	size_t n, m;
	std::cout << "¬ведите количество строк матрицы: ";
	std::cin >> n;
	std::cout << "¬ведите количество столбцов матрицы: ";
	std::cin >> m;

	int ** A = Create(n, m);

	Input( A, n, m );
	FillRandomNumbers(A, n, m);

	int* S = new int[n];
	Process(A, S, n, m);

	for (size_t i = 0; i < n; i++)
		std::cout << S[i] << ' ';
	std::cout << std::endl;

	//Print(A, n, m);

	delete[] S;

	Delete(A, n);

	return 0;
}
