// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define debug cout << "dfad\n";

// const ll m = 1e9 + 7;
/* subset21
int main() {
    ll n, k; cin >> n >> k;
    ll facn = 1;
    for (ll i = n; i > n-k; i--) {
        facn = (facn * i) % m;
    }
    cout << facn;
} */
/* 22
int main() {
    ll n, k; cin >> n >> k;
    ll facn = 1, fack = 1;
    for (ll i = n; i > n-k; i--) {
        facn = (facn * i) % m;
    }
    for (ll i = 2; i <= k; i++) {
        fack = (fack * i) % m;
    }
    auto exp = [&](ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    };
    cout << facn * exp(fack, m-2) % m;
} */