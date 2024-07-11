#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

bool mxm(ll &x, ll y) { return x < y ? x = y, 1 : 0; }
ll ab(ll x) { return x < 0 ? -x : x; }

char solve(ll a, ll b) {
    ll t; char c;
    if (ab(a) <= 5 || ab(b) <= 5) {
        t = a + b;
        if (mxm(t, a - b)) {
            if (mxm(t, a * b)) return '*';
            return '-';
        }
        if (mxm(t, a * b)) return '*';
    }

    if (b < 0) t = a - b, c = '-'; // a + b < a - b
    if (b >= 0) t = a + b, c = '+'; // a + b > a - b

    if (c == '+') {
        if (a < 0) return '+';
        else return '*';
    }
    if (c == '-') {
        if (a < 0) return '*';
        else return '-'; // ab < a + b < a - b
    }
}

int main() {
    ll a, b; cin >> a >> b;
    cout << solve(a, b);
}
