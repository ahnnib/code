#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        int n; string s; cin >> n >> s;
        int t1 = 0, t2 = n-1;
        while (s[t1] == 'W') t1++;
        while (s[t2] == 'W') t2--;
        cout << t2 - t1 + 1 << '\n';
    }
}