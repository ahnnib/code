#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n;
set<ll> res;

void f(ll n) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll j = n / i;
            res.insert((i - 1) * (j + 1));
            f((i - 1) * (j + 1));
        }
    }
}

int main() {
    freopen("woday.inp", "r", stdin);
    freopen("woday.out", "w", stdout);
    cin >> n;
    f(n);
    cout << res.size() << '\n';
    for (ll i : res) cout << i << ' ';
}
/*
Tối ưu: tính trước mảng pre[i]: các ước số của i: O(n log n)
insert tốn log -> tối ưu bằng mảng đánh dấu
Gọi đệ quy: Tốn hằng số -> dùng queue



const int N = 1e5 + 1;
vector<bool> vis(N); vector<int> p[N];
void pre()
{
    for(int i = 1 ; i < N ; i++)
    {
        for(int j = i ; j < N ; j += i)
            p[j].push_back(i);
    }
}
main() {
    pre();
    int n;  cin >> n;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(vis[u] == 1)
            continue;
        vis[u] = 1;
        for(int i = 0 ; i < p[u].size() ; i++)
        {
            int j = p[u][i];
            int nw = u / j;
            if(j <= nw)
            {
                int nww = (j - 1) * (nw + 1);
                if(vis[nww] == 0)
                    q.push(nww);
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
        if(vis[i])
            ans++;
    cout << ans << '\n';
    for(int i = 0 ; i < n ; i++)
        if(vis[i])
            cout << i << ' ';
}
*/