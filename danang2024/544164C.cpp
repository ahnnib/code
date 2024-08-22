#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int n, c[3][200001];
void sub1() {

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[1][i];
    for (int i = 1; i <= n; i++) cin >> c[2][i];
    if (n <= 8) sub1();
}