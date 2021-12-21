#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;

void input(float**, int, int);
void output(float**, int, int);
void find_X(float**, float, int, int, int&, int&);
void replace(float**, int, int, int);

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
	cout << "The array A:" << endl;
	input(A, m, n);
	output(A, m, n);
	float X;
	cout << "Enter the number you want to find: ";
	cin >> X;
	int iX = -1, jX = -1;
	find_X(A, X, m, n, iX, jX);
	if (iX != -1) {
		cout << "The first entry of the desired element X into the array has an index: " << iX << "; " << jX << endl;
		replace(A, m, iX, jX);
		cout << "New array:" << endl;
		output(A, m, n);
	}
	else {
		cout << "No X element was found in the array!" << endl;
	}
	for (int i = 0; i < m; i++) {
		delete[] A[i];
	}
	delete[] A;
}

void input(float** arr, int m1, int n1)
{
	srand(time(NULL));
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			arr[i][j] = -100 + (rand() % (int)pow(10, 3)) / pow(10, 3) * 200;
		}
	}
}

void output(float** arr, int m1, int n1)
{
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			cout << setw(10) << arr[i][j];
		}
		cout << endl;
	}
}

void find_X(float** arr, float X1, int m1, int n1, int &iX1, int &jX1) 
{
	bool R = 1;
	int i, j = 0;
	while (j < n1 && R) {
		if (j % 2 == 0) {
			i = 0;
			while (i < m1 && R) {
				if (arr[i][j] == X1) {
					iX1 = i;
					jX1 = j;
					R = 0;
				}
				i++;
			}
		}
		else {
			i = m1 - 1; 
			while (i >= 0 && R) {
				if (arr[i][j] == X1) {
					iX1 = i;
					jX1 = j;
					R = 0;
				}
				i--;
			}
		}
		j++;
	}
}

void replace(float** arr, int m1, int iX1, int jX1)
{
	float cop;
	cop = arr[iX1][jX1];
	arr[iX1][jX1] = arr[m1 / 2 + m1 % 2 - 1][jX1];
	arr[m1 / 2 + m1 % 2 - 1][jX1] = cop;
}