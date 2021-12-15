#include <iostream>
#include <iomanip>
using namespace std;

void input_2(float** arr2, int m1)
{
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m1; j++) {
			cin >> arr2[i][j];
		}
	}
	cout << endl;
}

void output_2(float** arr2, int m1)
{
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m1; j++) {
			cout << setw(5) << arr2[i][j];
		}
		cout << endl;
	}
}

void output_1(float arr1[], int n1)
{
	for (int i = 0; i < n1; i++) {
		printf("%.2f", arr1[i]);
		cout << "  ";
	}
	cout << endl;
}

int creating_B(float arr1[], float** arr2, int m1) {
	int n1 = 0;
	for (int i = 0; i < m1; i++) {
		if (arr2[i][m1 - 1 - i] < 0) {
			arr1[n1] = arr2[i][m1 - 1 - i];
			n1++;
		}
	}
	return n1;
}

int main()
{
	int m = 5;
	int n;
	float** A;
	float* B = 0;
	A = new float*[m];
	for (int i = 0; i < m; i++) {
		A[i] = new float[m];
	}
	for (int i = 0; i < m; i++) {
		B = new float[m];
	}
	cout << "Enter the matrix A:" << endl;
	input_2(A, m);
	cout << "The matrix A:" << endl;
	output_2(A, m);
	n = creating_B(B, A, m);
	if (n == 0) {
		cout << "The side diagonal does not contain negative elements!" << endl;
	}
	else {
		cout << "The second massive:" << endl;
		output_1(B, n);
	}
	system("pause");
	return 0;
}