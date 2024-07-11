#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    short n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    long ans = 2147483647;
    for(int i = 0; i < 1<<n; i++)
    {
        long sumA = 0, sumB = 0;

		for(int j = n-1; j >= 0; j--)
        {
			if(i & 1<<j) sumB += p[j];
            else sumA += p[j];
		}
        ans = min(abs(sumA - sumB), ans);
	}
    cout << ans;
}