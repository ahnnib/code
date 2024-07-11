#include <iostream>
#include <stack>

using namespace std;

int n, a[400001], l1[400001], r1[400001], l2[400001], r2[400001];

void minleft()
{
    stack <int> stack;
    for(int i = 1; i <= n; i ++)
    {
        while(!stack.empty() && a[stack.top()] >= a[i])
            stack.pop();

        if(stack.empty()) l1[i] = 0;
        else l1[i] = stack.top();

        stack.push(i);
    }
}

void minright()
{
    stack <int> stack;
    for(int i = n; i >= 1; i --)
    {
        while(!stack.empty() && a[stack.top()] >= a[i]) stack.pop();

        if(stack.empty()) r1[i] = n + 1;
        else r1[i] = stack.top();

        stack.push(i);
    }
}

void maxleft()
{
    stack <int> stack;
    for(int i = 1; i <= n; i ++)
    {
        while(!stack.empty() && a[stack.top()] <= a[i]) stack.pop();

        if(stack.empty()) l2[i] = 0;
        else l2[i] = stack.top();

        stack.push(i);
    }
}

void maxright()
{
    stack <int> stack;
    for(int i = n; i >= 1; i ++)
    {
        while(!stack.empty() && a[stack.top()] <= a[i]) stack.pop();

        if(stack.empty()) r2[i] = 0;
        else r2[i] = stack.top();

        stack.push(i);
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
