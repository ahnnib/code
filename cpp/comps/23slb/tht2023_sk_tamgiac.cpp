#include <iostream>
using namespace std;

#define int long long

const int N = 1e6 + 1;
int prime[N];
void sang()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < N; i++)
        if (prime[i] == 0)
            for (int j = i * i; j < N; j += i)
                prime[j] = 1;
}

void trau(int n)
{
    int res = 0;
    for (int i = 1; i <= n-2; i++)
        for (int j = i+1; j <= n-1; j++)
            for (int k = j+1; k <= n; k++)
                {
                    if (prime[i+j] == 1 && prime[j+k] == 1 && prime[i+k] == 1) res++;
                }

    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sang();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        trau(n);
    }
}
