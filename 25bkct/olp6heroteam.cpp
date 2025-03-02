#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 998244353;

ll n;
struct P { ll p, q; } A[2501];

ll S(int i, int j, int k) { // Calculates synnergy for chosen i, j, k
    ll a = A[i].p, b = A[j].p, c = A[k].p;
    ll x = A[i].q, y = A[j].q, z = A[k].q;

    ll D = 1 + (x != y) + ((x != z) && (y != z));

    ll res = 1, Q = (a + b + c) % mod;
    for (; D; D--) {
        res *= Q;
        res %= mod;
    }
    return res;
}

void sub1() {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (A[k].p >= A[i].p + A[j].p) {
                    continue;
                }
                res += S(i, j, k);
                res %= mod;
                // cout << "Choosing (" << i << ", " << j << ", " << k << "): " << S(i, j, k) << '\n';
            }
        }
    }
    cout << res;
}
void sub3() {
    ll res = 0;
    ll sum[2501] = {};
    sum[0] = A[0].p;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + A[i].p;
        sum[i] %= mod;
    }

    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            int l = j+1, r = n, mid;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (A[mid].p < A[l].p + A[r].p) l = mid + 1;
                else r = mid - 1;
            }
            res += 1ll * (i + j) % mod * (r - j+1 + 1) % mod + (sum[r] - sum[j] + mod) % mod;
            res %= mod;
        }
    }
    cout << res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].p >> A[i].q;
    }

    sort(A, A + n, [](const P &u, const P &v) {
        if (u.p == v.p) {
            return u.q < v.q;
        }
        return u.p < v.p;
    });

    // for (int i = 0; i < n; i++) {
    //     cout << A[i].p << ' ' << A[i].q << '\n';
    // }

    bool s3 = 1;
    for (int i = 1; i < n; i++) {
        s3 &= A[i].p == A[i-1].p;
    }
    if (s3) sub3();
    if (n <= 200) sub1();
}