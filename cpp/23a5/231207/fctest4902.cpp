#include <iostream>
#include <map>
using namespace std;

#define int long long

const int N = 435;
int minPrime[N];
void minprime()
{
    for (int i = 2; i * i < N; i++)
        if (minPrime[i] == 0) for (int j = i * i; j < N; j += i)
            if (minPrime[j] == 0) minPrime[j] = i;
    for (int i = 2; i < N; i++)
        if (minPrime[i] == 0) minPrime[i] = i;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    minprime();

    int n, k;
    while (cin >> n >> k)
    {
        map<int, int> ts;
        for (int i = n; i >= n - k + 1; i--) // n(n - 1)(n - 2)...(n - k + 1)
        {
            int x = i;
            while (x > 1) ts[minPrime[x]]++, x /= minPrime[x];
        }

        for (int i = 1; i <= k; i++) // k!
        {
            int x = i;
            while (x > 1) ts[minPrime[x]]--, x /= minPrime[x];
        }

        int ans = 1;
        for (auto &[x, y] : ts) ans *= (y + 1);
        cout << ans << '\n';
    }
}