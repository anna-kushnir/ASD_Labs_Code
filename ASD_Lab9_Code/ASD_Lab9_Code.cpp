/*Задано матрицю дійсних чисел A[m, n]. При обході матриці по стовпчиках
визначити в ній присутність заданого дійсного числа X і його місцезнаходження.
Обміняти знайдене значення Х з елементом середнього рядка.*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

float GetRandomNumberFloat(float min, float max, int precision)
{
	srand(time(NULL));
	float num;
	num = rand() % (int)pow(10, precision);
	num = min + (num / pow(10, precision)) * (max - min);
	return num;
}

void input(float** arr, int m1, int n1)
{
	float Min, Max;
	int Precision;
	cout << "Enter the minimum possible array value: "; cin >> Min;
	cout << "Enter the maximum possible array value: "; cin >> Max;
	cout << "Enter the precision of the array elements: "; cin >> Precision;
	cout << "The array A:" << endl;
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			arr[i][j] = GetRandomNumberFloat(Min, Max, Precision);
		}
	}
}

void output(float** arr, int m1, int n1)
{
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			cout << setw(7) << arr[i][j];
		}
		cout << endl;
	}
}



int main()
{
	int m, n;
	cout << "Enter the number of rows in the two-dimensional array: "; cin >> m;
	cout << "Enter the number of columns in the two-dimensional array: "; cin >> n;
	float** A;
	A = new float* [m];
	for (int i = 0; i < m; i++) {
		A[i] = new float[n];
	}
	input(A, m, n);
	output(A, m, n);


	for (int i = 0; i < m; i++) {
		delete[] A[i];
	}
	delete[] A;
}