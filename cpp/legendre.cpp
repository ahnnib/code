// tich lon nhat tap con S la so chinh phuong

#include <iostream>
#include <math.h>
using namespace std;

const long long mod = 1234567891;
long long expo(long long a, long long b)
{
	if (b == 0) return 1;
	long long t = expo(a, b/2) % mod;
	t = t * t % mod;
	return t * (b % 2 ? a : 1) % mod;
}

const int N = 1e5 + 1;
bool prime[N];
void sieve()
{
	prime[0] = prime[1] = 1;
	for (int i = 2; i * i < N; i++)
		if (!prime[i]) for (int j = i * i; j < N; j += i)
			prime[j] = 1;
}

long long vp(long long n, long long p)
{
	long long res = 0;
	long long t = p;
	for (int i = 1; n >= t; i++)
	{
		res += (n / t);
		t *= p;
	}
	return res;
}

int main()
{
	sieve();
	// cout << vp(10000, 2);
	int n;
	cin >> n;

	long long ans = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			long long tmp = vp(n, i);
			(ans *= expo(i, tmp - (tmp % 2))) %= mod;
			// cout << i << ' ' << ans << '\n';
		}
	}
	cout << ans;
}
