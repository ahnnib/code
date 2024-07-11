#include <iostream>
using namespace std;

#define debug cout << i << ' ';

void solve() {
    string s; cin >> s;
    int res = 0;
    int cntA = 0, i = 0;
    while (i < s.size()) {
        // AAAAAB
        // BAAAAAA
        if (s[i] == 'A') {
            while (s[i] == 'A') i++, cntA++;
            if (s[i] == 'B') res += cntA;
            cntA = 0;
            i++;
        }
        if (s[i] == 'B') {
            i++;
            while (s[i] == 'A') i++, cntA++;
        }
        res += cntA;
        cntA = 0;
    }
    cout << res;

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}
/*
*/