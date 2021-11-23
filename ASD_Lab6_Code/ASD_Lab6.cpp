#include <iostream>
using namespace std;

long long factorial(long i)
{
	long long f=1;
	while (i >= 1)
	{
		f *= i;
		i--;
	}
	return f;
}

double Sum(double ak_1, double bk_1, long n, long m)
{
	double ak, bk, S;
	if (n >= 1)
	{
		S = (ak_1 - bk_1) / factorial(m - n + 1);
		ak = 0.5 * (sqrt(bk_1) + 5 * sqrt(ak_1));
		bk = 2 * ak_1 * ak_1 + bk_1;
		n = n - 1;
		S = S + Sum(ak, bk, n, m);
	}
	else S = 0;
	return S;
}

int main()
{
	long n, m;
	double a1, b1, S;
	cout << "Enter the value of n: "; cin >> n;
	cout << endl;
	a1 = 1;
	b1 = 1;
	m = n;
	S = Sum(a1, b1, n, m);
	cout << "The sum of " << n << " members of the sequence: " << S << endl;
}