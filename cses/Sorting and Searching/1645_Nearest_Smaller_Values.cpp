#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<pair<int, int>> stack;

    // monotonic stack
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && stack.top().first >= a[i]) stack.pop();
        if (!stack.empty()) cout << stack.top().second+1 << ' ';
        else cout << "0 ";
        stack.push({a[i], i});
    }
}
/*
8
2 5 1 4 8 3 2 5
1 2 2 3 4 5 5 8

*/