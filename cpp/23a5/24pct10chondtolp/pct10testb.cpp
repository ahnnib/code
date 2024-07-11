#include <iostream>
using namespace std;

#define int long long

const int N = 1e6 + 1;

bool prime[N];
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < N; i++)
        if (!prime[i]) for (int j = i * i; j < N; j += i)
            prime[j] = 1;
}
int uoc[N];
void sanguoc()
{
    for (int i = 1; i < N; i++) for (int j = i; j < N; j += i) uoc[j]++;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    sieve(); sanguoc();


    // for (int i = 1; i < N; i++) cout << uoc[i] << ' ';
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;

        for (int i = a; i <= b; i++)
            if (!prime[uoc[i]]) ans++;

        cout << ans << '\n';
    }
}