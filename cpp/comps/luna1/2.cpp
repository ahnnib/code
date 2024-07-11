#include <iostream>
#include <stack>

using namespace std;

int n, a[4000001], l1[4000001], r1[4000001], l2[4000001], r2[4000001];

void minleft()
{
    stack <int> st;
    for(int i = 1; i <= n; i ++)
    {
        while(!st.empty() && a[st.top()] > a[i])
            st.pop();

        if(st.empty()) l1[i] = 0;
        else l1[i] = st.top();

        st.push(i);
    }
}

void minright()
{
    stack <int> st;
    for(int i = n; i >= 1; i --)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();

        if(st.empty()) r1[i] = n + 1;
        else r1[i] = st.top();

        st.push(i);
    }
}

void maxleft()
{
    stack <int> st;
    for(int i = 1; i <= n; i ++)
    {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();

        if(st.empty()) l2[i] = 0;
        else l2[i] = st.top();

        st.push(i);
    }
}

void maxright()
{
    stack <int> st;
    for(int i = n; i >= 1; i ++)
    {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();

        if(st.empty()) r2[i] = 0;
        else r2[i] = st.top();

        st.push(i);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    minleft(); minright(); maxleft(); maxright();
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int l = i - l2[i] - 1;
        int r = r2[i] - i - 1;
        ans += (l * r + l + r) * a[i];
    }
    for(int i = 1; i <= n; i ++)
    {
        int l = i - l2[i] - 1;
        int r = r2[i] - i - 1;
        ans -= (l * r + l + r) * a[i];
    }
    cout << ans;
}
