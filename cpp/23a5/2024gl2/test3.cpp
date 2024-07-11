#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define get_an_ac ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string to_str(ll n) {stringstream s; s << n; return s.str();}
ll count(ll l, ll r) {return floor(sqrt(r))-ceil(sqrt(l))+1;}
int main() {
	get_an_ac;
    // freopen("bai2.inp", "r", stdin);
    // freopen("bai2.out", "w", stdout);
    ll n, l = 1, r = 9, cnt = 1; cin >> n;
    while (true) {
    	if (n < count(l, r)*cnt) break;
    	else {n -= count(l, r)*cnt, l *= 10, cnt++; r = r*10+9;}
	}
	ll scp = count(1, (r-9)/10)+n/cnt+(n%cnt!=0);
    cout << to_str(scp*scp)[(n%cnt+cnt-1)%cnt] << "\n";
    return 0;
}