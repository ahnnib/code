#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>ii;
const ll mod=1e9+7;
ii dp[20][5433][181];
ll kq,l,r,coso[20];
vector<int>dg;
int q,k,P[11];

ii get(int pos,int sum1,int sum2,bool dabe)
{
    // first là tổng còn second là số lượng
    if(pos==-1&&__gcd(sum1, sum2) == 1)return ii{0,1};else
        if(pos==-1)return ii{0,0};
    if(dp[pos][sum1][sum2]!=ii{-1,0}&&dabe)return dp[pos][sum1][sum2];
    ii res={0,0};
    for(int i=0;i<=max(dg[pos],dabe*9);i++)
    {
        ii cc=get(pos-1,sum1+P[i],sum2+i,dabe|(i<dg[pos]));
        res.first=((res.first+cc.first)%mod+((i*coso[pos])%mod*(cc.second%mod))%mod)%mod;
        res.second+=cc.second;
    }
    if(dabe)dp[pos][sum1][sum2]=res;
    return res;
}
void get_dig(ll x) {
    dg.clear();
    for(;x>0;x/=10)dg.push_back(x%10);
}
ll call(ll x)
{
    if(x==0)return 0;
    get_dig(x);
    return get(dg.size()-1,0,0,0).second;
}
void sol() {

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    coso[0]=1;
    P[0]=0;
    for(int i=1;i<=9;i++)P[i]=i*i+P[i-1];
    for(int i=1;i<=18;i++)coso[i]=coso[i-1]*10%mod;
    for(int i=0;i<=19;i++)for(int j=0;j<=5432;j++)for(int k=0;k<=180;k++)dp[i][j][k]={-1,0};
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        // cout<<(call(r)-call(l-1)+mod*mod)%mod<<"\n";
        sol();
    }
    return 0;
}
