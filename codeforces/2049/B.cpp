#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t --) {
        int n; cin >> n;
        string s;
        cin >> s;
        s = ' ' + s + 'p';
        int j = 0;
        for(int i = 1; i <= n + 1; i ++)
            if(s[i] == 'p') {
                int pos = j + 1;
                for(int k = i - (i == n + 1); k > j - (i == n + 1); k --) {
                    a[pos] = k;
                    pos ++;
                }
                j = i;
            }
        bool ok = 1;
        int sum = 0;
        for(int i = n; i >= 1; i --) {
            sum += a[i];
            if(s[i] == 's') {
                int x = n - i + 1;
                int y = x * (x + 1) / 2;
                if(sum != y) ok = 0;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}