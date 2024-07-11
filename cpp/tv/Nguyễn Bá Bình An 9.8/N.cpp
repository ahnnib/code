#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> num;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        num.insert(a);
    }

    cout << num.size();
}