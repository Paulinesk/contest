#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int min = 0, max = 0;
	int N;
	cout << "¬ведите размерность массива: ";
	cin >> N;
	int * A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";

	}
	delete[]A;
	return 0;
	
}