#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define debug cout << "dfad\n";

// type, length
struct T { char t; int l; };

int main()
{
    int n, k; string s;
    cin >> n >> k >> s;

    s.push_back(' ');
    vector<T> v;

    int i = 0;
    while (i < n) { // nén xâu
        char t = s[i]; int l = 0;
        while (s[i] == t) i++, l++; i--;
        v.push_back({t, l});
        i++;
    }

    // for (T it : v) cout << it.l << ' ' << it.t << '\n';
    int res = 0; for (T it : v) res = max(res, it.l); // cout << it.t << ' ' << it.l << '\n';
    int nd = v.size();
    for (i = 0; i < nd-1; i++) {
        int dif = 0;
        bool d[123] = {};
        // cout << i << ": ";
        for (int j = i+1; j < nd; j++) {
            dif += !d[v[j].t]; d[v[j].t] = 1;
            if (dif > k+1) break;
            if (v[i].t == v[j].t) res = max(res, v[i].l + v[j].l);
            // cout << j << ' ';
        }
        // cout << '\n';
    }

    cout << res;
}