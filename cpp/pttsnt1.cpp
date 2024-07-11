#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define debug cout << "dfad\n";

bool mark[(int)1e6 + 501];

int main()
{
    map<int, int> a_times_b, a_div_b;

    int nx; cin >> nx;
    map<int, int> num1;
    for (int i = 0; i < nx; i++)
    {
        int a, b; // a_i ^ b_i
        cin >> a >> b;

        mark[a] = 1; num1[a] += b;
    }

    int ny; cin >> ny;
    map<int, int> num2;
    for (int i = 0; i < ny; i++)
    {
        int c, d; // c_i ^ d_i
        cin >> c >> d;

        mark[c] = 1; num2[c] += d;
    }

    for (int i = 1; i <= 1e6 + 500; i++)
    {
        if (!mark[i]) continue;
        a_times_b[i] = num1[i] + num2[i];
        a_div_b[i] = num1[i] - num2[i];
    }

    vector< pair<int, int> > ans1, ans2;

    for (auto &[x, y] : a_times_b) if (y != 0) ans1.push_back({x, y});
    for (auto &[x, y] : a_div_b) if (y != 0) ans2.push_back({x, y});

    cout << ans1.size() << '\n';
    for (pair<int, int> i : ans1) cout << i.first << ' ' << i.second << ' ';
    cout << '\n' << ans2.size() << '\n';
    for (pair<int, int> i : ans2) cout << i.first << ' ' << i.second << ' ';
}
