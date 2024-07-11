#include <iostream>
#include <math.h>
using namespace std;

const int mod = 10;
const int N = 1e6 + 1; bool prime[N];
int n;

void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < N; i++) if (prime[i] == 0)
        for (int j = i * i; j < N; j += i) prime[j] = 1;
}
long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}

int cal(int p) // k lớn nhất p^k <= n
{
    int k = 0; long long t = p;
    while (t <= n) t *= p, k++;
    return k;
}

void solve()
{
    long long ans = 1;
    // pttsnt 1 -> n + lấy lcm
    for (int p = 7; p <= n; p++)
        if (!prime[p]) (ans *= expo(p, cal(p))) %= mod;
    // xử lí ts 3, 2, 5
    long long t1 = cal(2), t2 = cal(5), t = min(t1, t2);
    ans *= expo(3, cal(3)) * expo(2, t1 - t) * expo(5, t2 - t);

    cout << ans % mod;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("tc.inp", "r", stdin);
    freopen("tc.out", "w", stdout);
    #endif

    sieve();

    while (cin >> n) solve(), cout << '\n';
}
/*
xét pttsnt của 1 số n bất kì
n tăng dần ~ max các số mũ của ts tăng theo
chỉ cần duyệt qua các tsnt p, với mỗi ts p
tính k lớn nhất sao cho p^k | n
-> duyệt tối đa PI(1e6) ~= 78498 ts
*/
