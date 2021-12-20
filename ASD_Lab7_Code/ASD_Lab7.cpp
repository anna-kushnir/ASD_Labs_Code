#include <iostream>
#include <iomanip>
using namespace std;

void output(char[], int);
int find_52(char[]);

int main()
{
	const int n = 10;
	int k = 0;
	char A[n], B[n], C[n];
	int number;
	for (int i = 0; i < n; i++)
	{
		A[i] = 60 - 2 * (i + 1);
		B[i] = 40 + 3 * (i + 1);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				C[k] = A[i];
				k++;
			}
		}
	for (int i = k; i < n; i++) {
		C[i] = 0;
	}
	cout << setw(20) << "The first massive: "; output(A, n);
	cout << setw(20) << "The second massive: "; output(B, n);
	cout << setw(20) << "The third massive: "; output(C, n);
	number = find_52(C);
	cout << "The first occurrence of a number 52 has an index i = " << number << 
		" (the " << number + 1 << " element of the third massive)" << endl;
	system("pause");
	return 0;
}

void output(char arr[], int m)
{
	for (int i = 0; i < m; i++)
		cout << setw(4) << arr[i];
	cout << endl;
}

int find_52(char arr[])
{
	int num, u = 0;
	bool r = 1;
	while (r)
	{
		if (arr[u] == 52)
		{
			num = u;
			r = 0;
		}
		u++;
	}
	return num;
}