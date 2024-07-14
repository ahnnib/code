#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

struct Xe { ll a, b; };

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("schedule.inp", "r", stdin);
    freopen("schedule.out", "w", stdout);
    #endif

    int n; cin >> n;
    Xe xe[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> xe[i].a, sum += xe[i].a;
    for (int i = 0; i < n; i++) cin >> xe[i].b;
    /* gia su co 2 danh sach thu tu sua xe P va Q thoa man tien phat: Phat(P) <= Phat(Q)
    xet 2 xe i va i+1. Trong do o P xe i duoc sua truoc, trong Q xe i+1 duoc sua truoc
    Goi T la so ngay sua xong den xe i-1
    Phat(P) <= Phat(Q) -> (T+b_i)*a_i + (T+b_i+b_i+1)*a_i+1 <= (T+b_i+1)*a_i+1 + (T+b_i+1+b_i)*a_i
    -> b_i * a_i+1 <= b_i+1 * a_i */
    sort(xe, xe + n, [](Xe &k, Xe &u) -> bool {
        return k.b * u.a < k.a * u.b;
    });

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += sum * xe[i].b;
        sum -= xe[i].a;
    }
    cout << res;
}