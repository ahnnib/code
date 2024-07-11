#include <bits/stdc++.h>
using namespace std;

bool func() { return (1 + 1 == 2); }

int main() {
    func();
    char ch = 'a';
    std::string str = "color preview\n";
    std::map<std::string, int> m = {
        {"CPU" , 25},
        {"RAM" , 30},
        {"Disk", 35},
    };
    // comment\
\
 \    line continuation
    /* block
        comment */
    std::cout << m["Disk"];
}

