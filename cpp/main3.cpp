#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 20;
ll validNumbers[N][10][2][2]; //dp[max. number of digits][lead digit][bool lead_zero][tight]

void reset () {memset(validNumbers, -1, sizeof(validNumbers));}

ll dfs(string &numstr, ll n, ll x, bool leading_zero, bool tight) {
    if (n == 0) return 1;

    //subproblem is already solved
    if (x != -1 && validNumbers[n][x][leading_zero][tight] != -1)
        return validNumbers[n][x][leading_zero][tight];
    int bound =  tight ? (numstr[numstr.length() - n] - '0') : 9;

    ll ans = 0;
    for (int digit = 0; digit <= bound; digit++) {

        //We  have a number with same consecutive digits which is NOT the case
        //of consecutive leading zeroes
        if ((digit == x) && (leading_zero == 0)) continue;

        //answer gets incremented by the number of possible n - 1 digit
        //integers that can follow our current digit
        ans += dfs(numstr, n - 1, digit, (leading_zero && digit == 0), (tight && (digit == bound)));
    }

    return validNumbers[n][x][leading_zero][tight] = ans;
}

int main() {
	// ll a, b; cin >> a >> b;

    // string a_str = to_string(a - 1);
    // string b_str = to_string(b);

    // reset();
    // ll ans1 = dfs(a_str, a_str.length(), -1, 1, 1);
    // reset();
    // ll ans2 = dfs(b_str, b_str.length(), -1, 1, 1);
    // cout << ans2 - ans1 << "\n";
    // return 0;

    long long n;
    std::cin >> n;
    reset();
    std::string digit_n = std::to_string(n);
    std::cout << dfs(digit_n, digit_n.size()-1, -1, 1, 1);
}