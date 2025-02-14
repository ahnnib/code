#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main()
{
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int j = 0;
    stack<int> st;
    for(int i = 1; i <= n; i ++)
    {
        st.push(i);
        while(!st.empty() && a[j] == st.top()) {
            st.pop();
            j++;
        }
    }
    cout << (st.empty() ? "NO" : "YES");
}