#include <iostream>
#include <stdlib.h>
using namespace std;

long long expo(long long a, long long b, long long mod)
{
	if (b == 0) return 1;
	long long t = expo(a, b/2, mod) % mod;
	t = t * t % mod;
	return t * (b % 2 ? a : 1) % mod;
}

bool millerTest(int d, int n)
{
	int a = 2 + rand() % (n - 4);

    int x = expo(a, d, n);

	if (x == 1 || x == n-1) return 1;

	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return 0;
		if (x == n-1) return 1;
	}

	return 0;
}

bool isPrime(int n, int k)
{
	// Corner cases
	if (n <= 1 || n == 4) return 0;
	if (n <= 3) return 1;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given number of 'k' times
	for (int i = 0; i < k; i++)
		if (!millerTest(d, n))
			return 0;

	return 1;
}

int main()
{
	int k = 4; // Number of iterations

	cout << "All primes smaller than 100: \n";
	for (int n = 1; n < 100; n++)
	if (isPrime(n, k))
		cout << n << " ";

	return 0;
}
