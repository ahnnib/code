// n mảnh ghép hình tam giác vuông cân. Có thể ghép thành hình vuông lớn?

#include <iostream>
#include <math.h>
using namespace std;

bool square(long long x)
{
    long long l = 1, r = 2e9, mid, res;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid * mid >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l * l == x;
    /*
    return sqrt(x) == (long long)sqrt(x);
    */
}
void test(long long x)
{
    long long l = 1, r = 2e9, mid, res;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid * mid >= x) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << ' ' << r << ' ' << mid << '\n';
}

void main1()
{
    int t;
    cin >> t;
    while (t --> 0)
    {
        long long n;
        cin >> n;
        if ((n % 4 == 0 && square(n / 4)) || (n % 2 == 0 && square(n / 2))) cout << "Yes\n";
        else cout << "No\n";
    }
}
void main2()
{
    long long n;
    cin >> n;
    cout << square(n / 2) << ' ' << square(n / 4);
}

int main()
{
    main1();
    // main2();
}