#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b)
{
    if (a.size() > b.size())
        swap(a, b); // a <= b

    int sa = a.size(),
        sb = b.size();

    string res;

    int delta = sb - sa;
    int sum = 0, carry = 0;
    for (int i = sa - 1; i >= 0; i--)
    {
        sum = a[i] + b[i + delta] - 96 + carry;
        res.push_back(sum % 10 + 48);
        carry = sum / 10;
    }
    for (int i = delta-1; i >= 0; i--)
    {
        sum = b[i] - 48 + carry;
        res.push_back(sum % 10 + 48);
        carry = sum / 10;
    }
    if (carry) res.push_back(carry + 48);

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int j = 0;
    while (j < 5) j++;
    cout << j;
}
/*
ABCDEFA
 l
      r
xxABCDEFxxx

xxABCDEFxxx
xxABCDEFxx
xxABCDEFx
xxABCDEF
xABCDEFxxx
xABCDEFxx
xABCDEFx
xABCDEF
ABCDEFxxx
ABCDEFxx
ABCDEFx
ABCDEF

12
*/
