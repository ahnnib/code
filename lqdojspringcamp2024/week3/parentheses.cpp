#include <iostream>
#include <stack>
using namespace std;

char f(char c) {
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
}

void solve() {
    string p; cin >> p;
    stack<char> st;
    bool ok = 1;
    for (char i : p) {
        if (i == '(' || i == '[' || i == '{') st.push(i);
        else if (!st.empty() && st.top() == f(i)) {
            st.pop();
        }
        else { ok = 0; break; }
    }
    if (!st.empty()) ok = 0; // dư ngoặc
    cout << (ok ? "YES" : "NO");
    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    #ifndef ONLINE_JUDGE
    #else
    freopen("parentheses.inp", "r", stdin);
    freopen("parentheses.out", "w", stdout);
    #endif
    long long t; cin >> t; while (t--) {
        solve();
    }
}