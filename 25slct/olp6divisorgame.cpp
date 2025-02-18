#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a = 0;
bool t = 1;

void add(ll score) {
    if (t) a += score;
    else a -= score;
}

void dq(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            add(i + n / i);
            t = !t;
            dq(i);
            dq(n / i);
            break;
        }
    }
}

int main() {
    ll n; cin >> n;
    dq(n);
    cout << a;
}