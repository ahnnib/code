#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e7 + 1;
bool prime[N];
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < N; i++)
        if (!prime[i]) for (int j = i * i; j < N; j += i)
            prime[j] = 1;
}

bool sntdx(int n)
{
    string t = to_string(n);
    int nd = t.size();
    for (int i = 0; i < nd / 2; i++)
        if (t[i] != t[nd - i - 1]) return 0;
    return !prime[n];
}

int main()
{
    sieve();

    long long a, b;
    cin >> a >> b;

    int l = ceil(sqrt(a)), r = floor(sqrt(b));
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (sntdx(i)) ans++;
    }

    cout << ans;
}