#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 3e5 + 1;

int n;
int s[MAX];

void sub1() {
    sort(s + 1, s + 1 + n);
    int M = 0, m = 2e9;
    for (int i = 1; i <= n; i++)
    {
        M = max(M, s[i] + s[n - i]);
        m = min(m, s[i] + s[n - i]);
    }
    cout << M - m;
}
void sub3() {
    vector<int> v0, v1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 0) v0.push_back(s[i]);
        if (s[i] == 1) v1.push_back(s[i]);
    }

    if (v0.size() == v1.size()) cout << 0;
    else cout << 1;
}
void sub24() {}

int main()
{
    cin >> n;
    bool s3 = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] > 1) s3 = 0;
    }

    if (s3) sub3();
    else if (n % 2 == 0) sub1();
    else sub24();
}