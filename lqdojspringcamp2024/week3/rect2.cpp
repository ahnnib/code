#include <iostream>
#include <stack>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
int m, n, h[500000], L[500000], R[500000];
void buildLeft() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}
void buildRight() {
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}
int main() {
    cin >> m >> n; for (int i = 0; i < n; i++) cin >> h[i];
    // L[i]: vi tri truoc i, gan i nhat, h[L[i]] < h[i]
    // R[i]: vi tri sau i
    buildLeft(); buildRight();
    ll res = 0; for (int i = 0; i < n; i++) res = max(res, 1ll * (R[i] - L[i] - 1) * h[i]);
    for (int i = 0; i < n; i++) h[i] = m - h[i]; // truong hop o mau xanh
    buildLeft(); buildRight();
    for (int i = 0; i < n; i++) res = max(res, 1ll * (R[i] - L[i] - 1) * h[i]);
    cout << res;
}