#include <iostream>
using namespace std;

int main() {
    long long a, b, x;
    cin >> a >> b >> x;

    long long count = 0;

    // Iterate over possible values of v
    for (long long v = 0; v <= b; ++v) {
        // u must satisfy: u ≡ -v (mod x), and 0 ≤ u ≤ a
        long long remainder = (-v % x + x) % x; // Handle negative remainder
        if (remainder > a) continue;           // No valid u if remainder > a

        // Find the range of u that satisfies the condition
        // u = remainder + k * x, where k is any integer
        count += (a - remainder) / x + 1;
    }

    cout << count << endl;
    return 0;
}
