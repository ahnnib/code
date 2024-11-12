#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
struct matrix{
	ll a[4][4];
	matrix(){
		memset(a,0,sizeof a);
	}
};
ll M;
ll mul(ll a,ll b){
	if(b==0){
		return 0;
	}
	ll t=mul(a,b/2);
	t=t+t;
	t%=M;
	if(b&1){
		t+=a;
		t%=M;
	}
	return t;
}
matrix operator * (matrix a, matrix b){
	matrix c;
	for(ll i=0;i<3;i++){
		for(ll j=0;j<3;j++){
			for(ll k=0;k<3;k++){
				c.a[i][j]+=mul(a.a[i][k],b.a[k][j]);
				c.a[i][j]%=M;
			}
		}
	}
	return c;
}
matrix lt(matrix a,ll b){
	if(b==0){
		matrix I;
		for(ll i=0;i<3;i++){
			I.a[i][i]=1;
		}
		return I;
	}
	matrix t=lt(a,b/2);
	t=t*t;
	if(b&1){
		t=t*a;
	}
	return t;
}
ll n;
ll x,y,m,t = 1;
int main(){
	// freopen("ONE4EVER.inp","r",stdin);
	// freopen("ONE4EVER.out","w",stdout);
	fast
	cin>>t;
	while(t--){
		ll a,b,k;
		cin>>a>>b>>M>>k;
		matrix tam;
		tam.a[0][0]=a;
		tam.a[0][1]=b;
		tam.a[1][1]=1;
		matrix ans;
		ans.a[0][0]=b%M;
		ans.a[1][0]=1;
		tam=lt(tam,k-1);
		tam=tam*ans;
		cout<<tam.a[0][0]<<"\n";
	}
}