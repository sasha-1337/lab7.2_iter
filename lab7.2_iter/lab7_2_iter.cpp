#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int row, const int col, const int Low, const int High) 
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int row, const int col)
{
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Min(int** a, const int rowCount, const int colCount)
{
	int imin = 0;
	int min = 0;
	int i = 0;

	for (int j = 0; j < colCount; j++) {
		min = a[0][j];
		for (i = 0; i < rowCount; i++)
			if ((j % 2) && a[i][j] < min) {
				min = a[i][j];
				imin = j;
			}
	}
	return imin;
}

int Max(int** a, const int rowCount, const int colCount) {

	cout << endl;
	int imax = 0;
	int max = 0;
	int i = 0;
	for (int j = 0; j < colCount; j++) {
		max = a[0][j];
		for (i = 0; i < rowCount; i++)
			if (!(j % 2) && a[i][j] > max) {
				max = a[i][j];
				imax = j;
			}
	}
	return imax;
}	

void change(int** a, const int rowCount, int imax, int imin) {
     
	for (int i = 0; i < rowCount; i++) {
		 int tmp = a[i][imin];
		a[i][imin] = a[i][imax];
		a[i][imax] = tmp;
	}
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -5;
	int High = 5;

	int k;
	cout << " k = "; cin >> k; // row
	int n; 
	cout << " n = "; cin >> n; // col

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	cout << " Створений масив: " << endl;
	Create(a, k, n, Low, High);
	Print(a, k, n);

	int imin = Min(a, k, n);
	int imax = Max(a, k, n);
	 
	cout << " Mодифікований: " << endl;
	change(a, k, imax, imin);
	Print(a, k, n);

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}