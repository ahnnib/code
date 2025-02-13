#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define el '\n'
#define fi first
#define se second

template <class T> bool maximize(T &x, T y) {
    if (x < y) { x = y; return 1; }
    return 0;
}
template <class T> bool minimize(T &x, T y) {
    if (x > y) { x = y; return 1; }
    return 0;
}

const bool MULTITEST = 0;
#define TASK "BOXES"

// -------------------------------- //

const int N = 20;

int GETBIT(int n, int bit) {
	return ((n >> bit) & 1);
}

int n, k; ll c[N+1][N+1];
ll dp[1 << N];

void SOLVE() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> c[i][j];
    	}
    }
    for (int msk = 0; msk < (1 << n); msk++) {
    	dp[msk] = 1e18;
    }
    dp[(1 << n) - 1] = 0;
    for (int msk = (1 << n) - 1; msk >= 0; msk--) {
    	// cout << msk << ' ' << dp[msk] << el;
    	for (int i = 1; i <= n; i++) {
    		if (GETBIT(msk, i - 1)) {
    			for (int j = 1; j <= n; j++) {
    				if (i == j) continue;
    				if (GETBIT(msk, j - 1)) {
    					minimize(dp[msk ^ (1 << (i - 1))], dp[msk] + c[i][j]);
    				}
    			}
    		}
    	}
    }
    ll res = 1e18;
    for (int msk = 0; msk < (1 << n); msk++) {
    	if (__builtin_popcount(msk) <= k) {
    		minimize(res, dp[msk]);
    	}
    }
    cout << res << el;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    int T = 1; if (MULTITEST) cin >> T;
    while (T--) SOLVE();
}