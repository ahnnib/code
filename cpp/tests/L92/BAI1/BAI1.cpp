#include <iostream>

int main() {
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);

    int d, x, y;
    std::cin >> d >> x >> y;
    int dist = x - y;
    std::cout << d / (x - y) + (d % dist ? 1 : 0);
}
