#include <iostream>
#include <stack>
using namespace std;

#define int long long

const int N = 4e5 + 1;

int n, a[N], minl[N], minr[N], maxl[N], maxr[N];

void minleft()
{
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) minl[i] = 0;
        else minl[i] = st.top();
        st.push(i);
    }
}

void minright()
{
    stack<int> st;
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) minr[i] = n + 1;
        else minr[i] = st.top();
        st.push(i);
    }
}

void maxleft()
{
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        if (st.empty()) maxl[i] = 0;
        else maxl[i] = st.top();
        st.push(i);
    }
}

void maxright()
{
    stack<int> st;
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) maxr[i] = 0;
        else maxr[i] = st.top();
        st.push(i);
    }
}

int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    minleft(); //minright(); maxleft(); maxright();
    for (int i = 1; i <= n; i++) cout << minl[i] << ' '; cout << '\n';
    // for (int i = 1; i <= n; i++) cout << minr[i] << ' '; cout << '\n';

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i - maxl[i] - 1;
        int r = maxr[i] - i - 1;
        ans += (l * r + l + r) * a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int l = i - minl[i] - 1;
        int r = minr[i] - i - 1;
        ans -= (l * r + l + r) * a[i];
    }
    cout << ans;
}

/*
3
1 2 3
4

4
3 1 7 2
31
*/