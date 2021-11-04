#include <iostream>
using namespace std;

long long factorial(long long i)
{
	long long f=1;
	while (i >= 1)
	{
		f = f * i;
		i--;
	}
	return f;
}

double Sum(double ak_1, double bk_1, long long k, long long m)
{
	double ak, bk, S;
	S = (ak_1 - bk_1) / factorial(m - k + 1);
	ak = 0.5 * (sqrt(bk_1) + 5 * sqrt(ak_1));
	bk = 2 * ak_1 * ak_1 + bk_1;
	if (k >= 1)
	{
		k = k - 1;
		S = S + Sum(ak, bk, k, m);
	}
	else S = 0;
	return S;
}

int main()
{
	long long n, m;
	double a, b, S;
	cout << "Enter the value of n: "; cin >> n; 
	cout << endl;
	a = 1;
	b = 1;
	m = n;
	S = Sum(a, b, n, m);
	cout << S << endl;
}