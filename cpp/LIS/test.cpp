#include <iostream>
#include <iosfwd>
#include <chrono>
#include <random>
using namespace std;

const string NAME = "test";
const int TEST = 2;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long rd(long long l, long long r) { return uniform_int_distribution<long long>(l, r)(rng); }

int main()
{

    for (int nTest = 1; nTest <= TEST; nTest++) {
        ofstream inp((NAME + ".inp").c_str());
        inp << rd(1, 100);
        inp.close();
    }
}