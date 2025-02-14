#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> st;
    st.push(0);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] < st.top()) {
            st.pop();
        }
        cout << st.top() << ' ';
        st.push(a[i]);
    }
}