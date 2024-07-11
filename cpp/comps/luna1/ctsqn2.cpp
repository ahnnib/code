#include <iostream>
#include <vector>
using namespace std;

const int mod = 0x3B9ACA07;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> tich;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (a[i] < a[j] && a[j] < a[k] && a[k] < a[i] + a[j])
                {
                    int tmp = 19 * a[i] + 19 * a[j] + 6 * a[k];
                    if (tmp % 7 == 0 || tmp % 6 == 0)
                    {
                        // cout << a[i] << ' ' << a[j] << ' ' << a[k] << '\n';
                        tich.push_back(a[i] + a[j] - a[k]);
                    }
                }
            }
        }
    }

    long long ans = 1;
    for (int i : tich) (ans *= i) %= mod;
    // cout << '\n';

    cout << (tich.empty() ? 0 : ans);
}