#include <iostream>
#include <stack>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("lineup.inp", "r", stdin);
    freopen("lineup.out", "w", stdout);
    #endif

    int n; cin >> n; int h[n+1]; for (int i = 1; i <= n; i++) cin >> h[i];

    stack<int> st; // st.top(): vị trí phần tử gần nhất bên trái > a[i]

    cout << 0 << ' ';
    st.push(1);

    for (int i = 2; i <= n; i++) {
        while (!st.empty() && h[i] >= h[st.top()]) st.pop();
        if (st.empty()) cout << "0 ";
        else cout << st.top() << ' ';
        st.push(i);
    }
}