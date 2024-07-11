#include <iostream>
#include <vector>
using namespace std;

const int N = 18;
long long dp[N][10]; // dp[len][digit]: số số có độ dài len với chữ số đầu tiên là d
long long f(long long n)
{
// t1t2t3...tn
    vector<int> digit;
    for (long long t = n; t; t /= 10) digit.push_back(t % 10);
    int nd = digit.size();


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) cout << dp[i][j] << ' ';
        cout << '\n';
    }

    long long res = 0;
    for (int i = 1; i < nd; i++)
        for (int j = 0; j <= 9; j++)
            res += dp[i][j];

    for (int i = nd-1; i >= 0; i--)
    {
        for (int d = (i == nd-1); d <= digit[i]; d++)
        {
            if (d != digit[i+1]) res += dp[i+1][d];
        }
        if (digit[i] == digit[i+1]) break;
    }

    return res;
}

int main()
{

    for (int d = 0; d <= 9; d++) dp[1][d] = 1;
    for (int len = 2; len <= N; len++)
        for (int d = 0; d <= 9; d++) for (int d2 = 0; d2 <= 9; d2++)
            if (d != d2) dp[len-1][d] += dp[len-2][d2];

    long long n;
    cin >> n;
    cout << f(n);

    // long long a, b;
    // cin >> a >> b;

    // cout << f(b) - f(a - 1);
}