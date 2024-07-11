#include <iostream>
#include <fstream>

using namespace std;

#include <chrono>
#include <random>
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define ll long long
ll rd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
#undef ll

int main() {
    const string NAME = "main";
    int tests = 100;
    for (int tc = 1; tc <= tests; tc++) {
        std::ofstream inp((NAME + ".inp").c_str());

        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if (!system(("fc " + NAME + ".out " + NAME + ".ans").c_str())) return cout << tc, 0;
    }
    return cout << -1, 0;
}