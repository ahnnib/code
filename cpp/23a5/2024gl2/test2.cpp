#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define get_an_ac ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string to_str(ll n) {stringstream s; s << n; return s.str();}
ll count(ll l, ll r) {return floor(sqrt(r))-ceil(sqrt(l))+1;} // so luong scp l -> r
int main() {
	get_an_ac;
    // freopen("bai2.inp", "r", stdin);
    // freopen("bai2.out", "w", stdout);
    for (int i = 1; i <= 100; i++)
    {
    // ll n, l = 1, r = 9, cnt = 1; cin >> n;
    ll n = i, l = 1, r = 9, cnt = 1;
    while (true) {
    	if (n < count(l, r)*cnt) break;
    	else {n -= count(l, r)*cnt, l *= 10, cnt++; r = r*10+9;}
	}
    ll t1 = (n%cnt+cnt-1)%cnt;
	ll scp = count(1, (r-9)/10)+n/cnt+(n%cnt!=0);
    // cout << to_str(scp*scp)[(n%cnt+cnt-1)%cnt] << "\n";
    cout << scp * scp << ' ' << t1 << ' ' << to_string(scp*scp)[t1] << '\n';
    }
    return 0;
}