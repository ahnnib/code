#include <iostream>

#define int long long

std::string x, n;
int ans = 0;
bool mark[11];

void shv(int pos)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (mark[i]) continue;
        n[pos] = x[i];

        mark[i] = 1;
        if (pos == x.size()-1)
        {
            int tmp = 0;
            for (int i = 0; i < x.size(); i++)
            {
                tmp = tmp * 10 + n[i]-48;
            }
            ans += tmp;
        }
        else
            shv(pos + 1);
        mark[i] = 0;
    }
} // 1000000000
/*123
*/
signed main()
{
    #ifndef ONLINE_JUDGE
    #else
        #define task "THV"
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif

    std::cin >> x;

    shv(0);

    std::cout << ans;
}

/*

*/
