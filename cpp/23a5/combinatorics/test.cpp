/*And if we meet forever now
pull the blackout curtains down*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define pb push_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define need_for_speed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9 + 7;
const int maxn=1e5+5;
int fact[maxn+1],karp[maxn+1],rev[maxn+1],countdivid[maxn+1];
void test_case(void){}
int sub(int a,int b,int p){return (1LL*a*b)%p;}
int mu(int  a,int n,int p)
{
	int res=a,ans=1;
	while(n)
	{
		if(n%2==1) ans=sub(ans,res,p);
		res=sub(res,res,p);
		n/=2;
	}
	return ans;
}
int main(){
	int t,p;
	cin>>t>>p;
	fact[0]=fact[1]=1;
	karp[0]=karp[1]=1;
    /*
    fact: fact
    karp: ifac
    rev: i
    countdivid: pw
    */
	countdivid[0]=countdivid[1]=0;
	for(int i=2;i<=maxn;++i)
	{
		rev[i]=i;
		countdivid[i]=countdivid[i-1];
		while(rev[i]%p==0)
		{
			rev[i]/=p;
			countdivid[i]++;

		}
		fact[i]=sub(fact[i-1],rev[i],p);
	}
	karp[maxn]=mu(fact[maxn],p-2,p);
	for(int i=maxn-1;i>=2;i--)
	{
		karp[i]=sub(karp[i+1],rev[i+1],p);
	}
	while(t--)
	{
		int n,k;
		cin>>n>>k;

		if(k>n||countdivid[n]>countdivid[k]+countdivid[n-k]) { cout<<0<<'\n'; continue;
		}
		// cout<<sub(fact[n],sub(karp[k],karp[n-k],p),p)<<'\n';
		cout << fact[n] << ' ' << karp[k] << ' ' << karp[n-k] << '\n';
	}
}