#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

const int mod = 10;
const int  N = 1e6 + 1;
int minPrime[N]; bool prime[N];
int n; unordered_map<int, int> nt;

void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = 1;
            }
        }
    }
}
void minprime()
{
    for (int i = 2; i * i < N; i++) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j < N; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
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
    int k = 0;
    long long t = p;
    while (t <= n) t *= p, k++;
    return k;
}

void solve()
{
    nt.clear();
    // pttsnt 1 -> n + lấy lcm
    for (int p = 2; p <= n; p++) {
        if (!prime[p]) {
            nt[p] = cal(p);
        }
    }
    // loại các ts nhân với nhau ra tận cùng 0
    int t = min(nt[2], nt[5]);
    nt[2] -= t;
    nt[5] -= t;
    //nhân hàng đơn vị các ts còn lại, chỉ lấy cs đơn vị
    long long ans = 1;
    for (auto &[a, b] : nt) {
        ans *= expo(a, b);
        ans %= mod;
    }

    cout << ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("tc.inp", "r", stdin);
    freopen("tc.out", "w", stdout);
    #endif

    sieve();

    while (cin >> n) {
        solve();
        cout << '\n';
    }
}
/*
xét pttsnt của 1 số n bất kì
n tăng dần ~ max các số mũ của ts tăng theo
chỉ cần duyệt qua các tsnt p, với mỗi ts p
tính k lớn nhất sao cho p^k | n
-> duyệt tối đa PI(1e6) ~= 78498 ts
*/
