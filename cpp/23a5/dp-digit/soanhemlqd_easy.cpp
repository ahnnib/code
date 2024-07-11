#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 20;
const int S = 9 * N;
int dp[N][2][S];

bool prime(long long n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

int calc(int n)
{
    if (n <= 0) return 0;

    vector<int> digits;
    for (int tmp = n; tmp; tmp /= 10) digits.push_back(tmp % 10);
    reverse(digits.begin(), digits.end());

    int nd = digits.size();
    for (int i = 0; i <= nd; i++) for (int tight : {0, 1})
            for (int s = 0; s < S; s++)
                dp[i][tight][s] = 0;
    dp[0][1][0] = 1;

    for (int i = 0; i < nd; i++) for (int tight : {0, 1})
    {
        for (int s = 0; s < S; s++)
        {
            if (!dp[i][tight][s]) continue;
            int lim = tight ? digits[i] : 9;
            for (int d = 0; d <= lim; d++)
            {
                dp[i+1][tight & (d == lim)][s + d] += dp[i][tight][s];
            }
        }
    }

    int ans = 0;
    for (int s = 0; s < S; s++)
        if (prime(s))
            for (int b : {0, 1})
                ans += dp[nd][b][s];

    return ans;

}

int main()
{

    int A, B;
    cin >> A >> B;

    cout << calc(B) - calc(A - 1);
}