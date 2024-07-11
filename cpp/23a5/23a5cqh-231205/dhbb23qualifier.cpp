#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;
int n;
int t[N];

void sub1()
{
    int k = n>>1;
    bool c = 1;
    for (; k > 0; k--)
    {
        c = 1;
        vector<int> a, b;
        for (int i = 1; i <= k; i++) a.push_back(t[i]);
        for (int i = k+1; i <= (k<<1); i++) b.push_back(t[i]);

        sort(a.begin(), a.end()); sort(b.begin(), b.end());

        for (int i = 0; i < k; i++)
            if (a[i] >= b[i])
            {
                c = 0;
                break;
            }

        if (c) { cout << k; return 0; }
    }
    cout << 0;
}
void sub2()
{

}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];


}