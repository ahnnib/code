#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define debug cout << "dfad\n";
#define int long long

int n;
vector<int> a;
int med;

long long median(vector<int> v)
{
    sort(begin(v), end(v));
    return v[(v.size() - 1) / 2];
}

void trau()
{
    int ans = 0;
    for (int l = 0; l < n; l++)
    {
        vector<int> tt;
        for (int r = l; r < n; r++)
        {
            tt.push_back(a[r]);
            if (median(tt) == med) ans++;
        }
    }
    cout << ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("median.inp", "r", stdin);
    freopen("median.out", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    med = median(a);

    trau();
}
/*
1 3 4 3 5
med = 3
để giữ nguyên trung vị phải:
- thêm 1 ptử: ptử >= m
- thêm 2 ptử: cái < cái >=

*/