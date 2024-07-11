#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a(1048577);

/*
queue
stack
queue
stack
queue
*/

void backtrack(vector<int> v)
{
    int s1 = (int) v.size();

    int med = v[s1 / 2];

    vector<int> v1, v2;
    for (auto i : v) {
        if (i > med) v2.push_back(i);
        if (i <= med) v1.push_back(i);
    }

    backtrack(v1);
    backtrack(v2);
}

{
    cin >> n;
    for (int i = 0; i < 1<<n; i++) cin >> a[i];

    backtrack(a);
}