/*
chia keo euler
co the lay 0 vien keo: ./cpp/cses/Mathematics/1716_Distributing_Apples.cpp
đặt y = x-1
=> y1 + y2 + .. + ym = m - n
m < n -> vô nghiệm
m >= n => đếm số cách nhét n-1 số 0 vào m-n + n - 1 số 1
đáp số: (m-1)C(n-1)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll m = 1e9 + 7;

int main() {
    ll n, k; cin >> n >> k;
    n--; k--;
    ll facn = 1, fack = 1;
    for (ll i = n; i >= n-k+1; i--) {
        (facn *= i) %= m;
    }
    for (ll i = 2; i <= k; i++) {
        (fack *= i) %= m;
    }
    auto exp = [&](ll a, ll b) -> ll {
        ll res = 1;
        while (b) { if (b&1) (res*=a)%=m; (a*=a)%=m; b>>=1; }
        return res;
    };
    cout << facn * exp(fack, m-2) % m;
}