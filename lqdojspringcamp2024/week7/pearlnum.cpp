/* giới hạn lớn
const int MAX_SUM = 9 * 9 * 19;

int state[MAX_SUM + 1]; // 0/1/2/3: unvisited/visited/happy/sad
ll sumsq(ll x) {
    ll sum = 0;
    for (; x; x /= 10) sum += (x % 10) * (x % 10);
    return sum;
}
int dfs(int s) {
    if (s == 1) {
        return state[s] = 2;
    }
    if (state[s] == 1) {
        // cycle => sad
        return state[s] = 3;
    }
    if (state[s] == 2 || state[s] == 3) {
        return state[s];
    }
    // Mark as visited
    state[s] = 1;
    int nxt = sumsq(s);
    int res = dfs(nxt);
    state[s] = res;
    return res;
}

ll dp[18][MAX_SUM];
vector<int> dig;
ll f(int pos, int sumSq, bool tight) {
    if (pos < 0) {
        return state[sumSq] == 3;
    }
    if (!tight && dp[pos][sumSq] != -1) return dp[pos][sumSq];
    ll res = 0; int lim = tight ? dig[pos] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(pos - 1, sumSq + d * d, tight && (dig[pos] == d));
    }
    if (!tight) dp[pos][sumSq] = res;
    return res;
}

void get(ll x) {
    dig.clear();
    dig.shrink_to_fit(); // Destroys the memory scope allocated for "dig"
    for (; x; x /= 10) dig.push_back(x % 10);
}

ll l, r;
void sol() {
    cin >> l >> r;
    get(r);
    ll g2 = f(dig.size()-1, 0, 1);
    get(l-1);
    ll g1 = f(dig.size()-1, 0, 1);
    cout << g2 - g1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof dp);
    state[0] = 3;
    for (int s = 1; s <= MAX_SUM; s++) {
        if (state[s] == 0) dfs(s);
    }

    int t = 1;
    cin >> t;
    while(t--) sol();
}
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll sumsq(ll x) {
    ll sum = 0;
    for (; x; x /= 10) sum += (x % 10) * (x % 10);
    return sum;
}
bool happy(ll x) {
    while (x > 9) {
        x = sumsq(x);
    }
    return x == 1 || x == 7;
}

ll dp[18][1539];
vector<int> dig;
ll f(int pos, int sumSq, bool tight) {
    if (pos < 0) {
        return !happy(sumSq);
    }
    if (!tight && dp[pos][sumSq] != -1) return dp[pos][sumSq];
    ll res = 0; int lim = tight ? dig[pos] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(pos - 1, sumSq + d * d, tight && (dig[pos] == d));
    }
    if (!tight) dp[pos][sumSq] = res;
    return res;
}

void get(ll x) {
    dig.clear();
    dig.shrink_to_fit(); // Destroys the memory scope allocated for "dig"
    for (; x; x /= 10) dig.push_back(x % 10);
}

ll l, r;
void sol() {
    cin >> l >> r;
    get(r);
    ll g2 = f(dig.size()-1, 0, 1);
    get(l-1);
    ll g1 = f(dig.size()-1, 0, 1);
    cout << g2 - g1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    int t = 1;
    cin >> t;
    while(t--) sol();
}