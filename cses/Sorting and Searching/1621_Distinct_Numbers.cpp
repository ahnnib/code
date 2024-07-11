#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    set<int> set;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        set.insert(a);
    }
    cout << set.size();
}