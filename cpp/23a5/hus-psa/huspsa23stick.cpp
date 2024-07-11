#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (a[i] == a[j] || a[i] == a[k] || a[j] == a[k])
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}