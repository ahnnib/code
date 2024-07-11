#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
int d[15], N;

long long getnum()
{
    long long num = 0;
    for (int i = 0; i < N; i++) num = num * 10 + d[i];
    return num;
}

int main()
{

    string n;
    cin >> n;
    N = n.size();
    for (int i = N-1; i >= 0; i--) d[i] = n[i] - 48;

    long long ans = 9223372036854775807ll;
    // TH1: thế 0 chữ số
    if (getnum() % 4 == 0) ans = min(ans, getnum());
    // TH2: thế 1 chữ số
    for (int i = 0; i < N; i++)
    {
        int old = d[i];
        for (int d2 = (i == 0); d2 <= 9; d2++)
        {
            d[i] = d2;
            long long num = getnum();
            if (num % 4 == 0) ans = min(ans, num);
        }
        d[i] = old;
    }
    // TH3: thế 2 chữ số
    for (int i = 0; i < N-1; i++)
    {
        int old_i = d[i];
        for (d[i] = (i == 0); d[i] <= 9; d[i]++)
        {
            for (int j = i+1; j < N; j++)
            {
                int old_j = d[j];
                for (d[j] = 0; d[j] <= 9; d[j]++)
                {
                    long long num = getnum();
                    // cout << num << '\n';
                    if (num % 4 == 0) ans = min(ans, num);
                }
                d[j] = old_j;
            }
        }
        d[i] = old_i;
    }

    cout << ans;
}