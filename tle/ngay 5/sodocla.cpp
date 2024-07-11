#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll mul_mod(ll a, ll b, const ll mod) { // haxbaxl
    ll res = 0, c;
    for (b %= mod; a; a & 1 ? b >= mod - res ? res -= mod : 0, res += b : 0, a >>= 1, (c = b) >= mod - b ? c -= mod : 0, b += c);
    return res % mod;
}
ll bp(ll a, ll k, ll n){
    a=a%n;
    ll res=1;
    while(k){
        if (k & 1)
            res = mul_mod(res,a,n);
        a =mul_mod(a,a,n);
        k /= 2;
    }
    return res;
}
bool test(ll a, ll n, ll k, ll m){
    ll mod=bp(a, m, n);
    if(mod==1||mod==n-1)
            return true;
    for(ll l=1;l<k;++l){
        mod=mul_mod(mod,mod,n);
        if(mod==n-1)
            return true;
    }
    return false;
}
bool rm(ll n){// rabin miller (vnoi)
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n < 11)
        return false;
    ll k = 0, m = n - 1;
    while (m % 2 == 0){
        m /= 2;
        k++;
    }
    const static ll op=3;
    for (ll i=0;i<op;++i){
        ll a = rand()%(n-3)+2;
        if (!test(a,n,k,m))
            return false;
    }
    return true;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
	#else
	freopen("sodocla.inp", "r", stdin);
	freopen("sodocla.out", "w", stdout);
	#endif

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<"NO"<<"\n";
			continue;
		}
		if(rm(n)==true){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	}
}