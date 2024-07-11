#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 1;
int n, a[MAX];

void sub3()
{
    cout << a[(n + 1) / 2];
}

int main()
{
    bool s3 = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // for (int i = 2; i <= n; i++) if (a[i] < a[i-1]) { s3 = 0; break; }
    // if (s3) { sub3(); return 0; }

    vector<int> med;
    for (int i = 1; i <= n; i++)
    {
        vector<int> v;
        for (int j = i; j <= n; j++)
        {
            v.push_back(a[j]);
            sort(v.begin(), v.end());
            med.push_back(v[(v.size() + 1) / 2 - 1]);
        }
    }

    sort(med.begin(), med.end());

    cout << med[(med.size() + 1) / 2 - 1];
}
/*
x x x x x x
. . . . . .

*/