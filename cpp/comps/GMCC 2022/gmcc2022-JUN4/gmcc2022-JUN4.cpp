#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int an, ad, bn, bd, ansn, ansd;
    char c; // for the character '/' in x / y

    cout << "A = "; cin >> an >> c >> ad;
    cout << "B = "; cin >> bn >> c >> bd;

    int lcm = ad * bd / __gcd(ad, bd);

    ansd = lcm;
    ansn = an * (lcm / ad) + bn * (lcm / bd);

    if (ansn / ansd < 1)
        cout << "ANS = " << ansn % ansd << '/' << ansd;
    else
        cout << "ANS = " << ansn / ansd << ", " << ansn % ansd << '/' << ansd;

    return 0;
}
