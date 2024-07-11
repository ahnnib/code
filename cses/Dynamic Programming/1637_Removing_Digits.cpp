#include <iostream>
#include <vector>
using namespace std;

int max_digit(int n)
{
    char res = 0;
    while (n) res = max(n % 10, (int) res), n /= 10;
    return res;
}

int main()
{
    int n;
    cin >> n;

    // greedy code
    /*
    int steps = 0;
    while (n)
        n -= max_digit(n),
        steps++;

    cout << steps;
    */

    // dp code
    vector<int> dp (n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int x = i;
        while (x)
            dp[i] = min(dp[i], dp[i - x % 10] + 1),
            x /= 10;
    }

    cout << dp[n];
}