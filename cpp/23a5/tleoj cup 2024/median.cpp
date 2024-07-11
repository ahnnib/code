#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5005;
int n;
int a[N];
int med[N][N];

void sub1()
{

}
void sub2() {}
void sub3() {}
void sub4() {}
void sub5() {}
void sub67() {}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("median.inp", "r", stdin);
    freopen("median.out", "w", stdout);
    #endif

    bool s1 = 1;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i) s1 = 0;
    }

    // if (s1) sub1();
    // if (n <= 60) sub2();
    // if (n <= 100) sub3();
    // if (n <= 300) sub4();
    // if (n <= 500) sub5();
    // else sub67();

    long long ans[N] = {};
    for (int l = 1; l <= n; l++)
    {
        vector<int> v;
        for (int r = l; r <= n; r++)
        {
            v.push_back(a[r]);
            sort(v.begin(), v.end());
            ans[v[(v.size()-1)/2]]++;
            // cout << l << ' ' << r << ' ' << v[(v.size()-1)/2] << '\n';
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[a[i]] << ' ';
}