#include <iostream>
using namespace std;

int main()
{
    int n, p, h; string s; cin >> n >> p >> h >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') continue;
        if (s[i] == 'P') p++;
        if (s[i] == 'H') h++;
        if (s[i] == 'M') {
            if (h > 1) h--;
            else if (p > 1) p--, cnt++;
            else return cout << -1, 0;
        }
    }
    cout << cnt;
}
