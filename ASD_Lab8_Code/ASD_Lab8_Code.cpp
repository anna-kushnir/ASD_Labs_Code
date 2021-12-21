#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void input_2(float**, int);
void output_2(float**, int);
int creating_B(float[], float**, int);
void output_1(float[], int);
void sorting(float[], int);

int main()
{
	int m = 5;
	int n;
	float** A;
	float* B;
	A = new float*[m];
	for (int i = 0; i < m; i++) {
		A[i] = new float[m];
	}
	B = new float[m];
	input_2(A, m);
	cout << "The matrix A:" << endl;
	output_2(A, m);
	n = creating_B(B, A, m);
	if (n == 0) {
		cout << "The side diagonal does not contain negative elements!" << endl;
	}
	else {
		cout << "The second array:" << endl;
		output_1(B, n);
		sorting(B, n);
		cout << "Sorted one-dimensional array:" << endl;
		output_1(B, n);
	}
	for (int i = 0; i < m; i++)
		delete[] A[i];
	delete[] A;
	delete[] B;
	system("pause");
	return 0;
}

void input_2(float** arr2, int m1)
{
	srand(time(NULL));
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m1; j++) {
			arr2[i][j] = (float)rand() / RAND_MAX * 2 * 100 - 100;
		}
	}
}

void output_2(float** arr2, int m1)
{
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m1; j++) {
			printf("%f10.2", arr2[i][j]);
		}
		cout << endl;
	}
}

int creating_B(float arr1[], float** arr2, int m1) {
	int n1 = 0;
	for (int i = 0; i < m1; i++) {
		if (arr2[i][m1 - i - 1] < 0) {
			arr1[n1] = arr2[i][m1 - i - 1];
			n1++;
		}
	}
	return n1;
}

void output_1(float arr1[], int n1)
{
	for (int i = 0; i < n1; i++) {
		printf("%.2f", arr1[i]);
		cout << "  ";
	}
	cout << endl;
}

void sorting(float arr1[], int n1)
{
	int i, j;
	float cop;
	for (i = 1; i < n1; i++) {
		cop = arr1[i];
		j = i - 1;
		while (j >= 0 && arr1[j] > cop) {
			arr1[j + 1] = arr1[j];
			j--;
		}
		arr1[j + 1] = cop;
	}
}