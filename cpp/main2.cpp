#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define hetcuu ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
    ll pos, val;
    node(ll y, ll z){pos = y; val = z;}
};
vector<node> d['z'+5];
ll m['z'+1][2000005];
bool check(char id, ll k, ll l, ll r){
    int kq = 0;
    for(char c = 'a'; c <= 'z'; c++){
        if(c != id)kq += (m[c][r] - m[c][l-1] > 0);
    }
    return kq <= k;
}

ll bs(char id, ll x){ // >= x
    ll l = 0, r = d[id].size()-1, m , kq = -1;
    while(l<=r){
        m = (l+r)/2;
        if(check(id, x, d[id][m].pos+1, d[id].rbegin()->pos)){
            kq = m;
            r = m-1;
        }else l = m+1;
    }
    if(kq == -1)return 0;
    return d[id].rbegin()->val - d[id][kq].val;
}
void push(char c, ll sl, ll pos){
    d[c].push_back(node(pos, sl));
    d[c].rbegin()->val += d[c][d[c].size()-2].val;
}
void add(int i){for(char c = 'a'; c <= 'z'; c++)m[c][i] += m[c][i-1];}
int main(){
    hetcuu
    ll n, k, c = 0, res = 0; cin >> n >> k;
    string s; cin >> s; s = '*' + s + '*';
    for(char c = 'a'; c <= 'z'; c++)push(c, 0, 0);
    for(ll i = 1; i <= n; i++){
        m[s[i]][i]++;
        add(i);
        c++;
        if(s[i+1] != s[i]){
            push(s[i], c, i);
            res = max(res, bs(s[i], k));
            c = 0;
        }
    }
    cout << res;
}
