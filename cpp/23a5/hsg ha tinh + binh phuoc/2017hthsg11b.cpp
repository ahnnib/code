#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("count.inp", "r", stdin);
    freopen("count.out", "w", stdout);
    #endif

    // int m, n;
    // cin >> m >> n;
    // int a[m], b[n];
    // map<int, bool> mark;
    // for (int i = 0; i < m; i++) cin >> a[i];
    // for (int i = 0; i < n; i++) cin >> b[i];

    // sort(a, a + m); sort(b, b + n);

    // int l = 0, r = m-1, mid, res;
    // for (int i = 0; i < n; i++)
    // {
    //     while (l <= r)
    //     {
    //         mid = (l + r) >> 1;
    //         if (a[mid] >= r) r = mid - 1;
    //         else l = mid + 1;
    //     }

    //     if (a[mid] == b[i])
    // }
    int n,m;
    cin>>n>>m;
    unordered_set<int>myset;
    while(n--)
    {
        int x;
        cin>>x;
        myset.insert(x);
    }
    int count=0;
    while(m--)
    {
        int x;
        cin>>x;
        if(myset.find(x)==myset.end()) count++; // ko tim thay -> tra ve vi tri cuoi
    }
    cout<<count;
}