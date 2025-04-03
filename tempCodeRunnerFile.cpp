#include <bits/stdc++.h>
#define task "GEN"
#define int unsigned long long
using namespace std;

const int N = 1e3;

int a[N+5], b[N+5], dp[N+5][N+5];

bool prime(int n) {
	if (n < 2) return 0;
	else if (n < 4) return 1;
	else if (!min(n%2, n%3)) return 0;
	
	for (int x = 5; x*x <= n; x += 6) {
		if (!min(n%x, n%(x+2))) return 0;
	}
	
	return 1;
}

bool check1(int n) {
	int sqr = (int)sqrt(n);
	
	return sqr*sqr == n;
}

bool check2(int n) {
	int l = 1, r = 2154435, ans = 0;
	
	while (l <= r) {
		int mid = (l+r)/2;
		
		if (mid*mid*mid <= n) {
			l = (ans = mid)+1;
		}
		else {
			r = mid-1;
		}
	}
	
	if (ans*ans*ans != n) return 0;
	
	return prime(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    string A, B;
    
    getline(cin, A); A += " ";
    getline(cin, B); B += " ";
    
    int n = 0, m = 0, v = 0;
    
    for (auto x : A) {
    	if (x == ' ') {
    		a[++n] = v, v = 0;
		}
		else {
			v = v*10+x-'0';
		}
	}
	
	for (auto x : B) {
		if (x == ' ') {
			b[++m] = v, v = 0;
		}
		else {
			v = v*10+x-'0';
		}
	}
	
	for (int x = 1; x <= n; x++) {
		if (check1(a[x])) continue;
		if (check2(a[x])) continue;
		
		a[x] = 0;
	}
	
	for (int x = 1; x <= m; x++) {
		if (check1(b[x])) continue;
		if (check2(b[x])) continue;
		
		b[x] = 0;
	}
	
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
			
			if (a[x] == b[y] && a[x] > 0) {
				dp[x][y] = max(dp[x][y], dp[x-1][y-1]+1);
			}
		}
	}
	
	return cout << dp[n][m] << "\n", 0;
}