#include <bits/stdc++.h>
using namespace std;

#define task "DYSLEXIA"
#define inout freopen(task".inp", "r", stdin); \
              freopen(task".out", "w", stdout);
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);


const char B64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int position[256];
void initBase64(){
    for (int i = 0; i < 64; i++) {
        position[B64[i]] = i;
    }
}

#define MAX 10000001
int n;
string S64;
char S[MAX];
int ptr = 0;
const long long mod = 1e9+7;
void b64Conversion(const string &s){
    for (char c: s){
        int x = position[c];
        for (int i = 0; i < 6; i++){
            S[ptr++] = (x & 1) + '0';
            x >>= 1;
        }
    }
}

int main(){
    fast
    // inout


    cin >> n >> S64;
    initBase64(); b64Conversion(S64);

    // main logic goes here
    // std::cout << n << ' ' << S64;
    // std::cout << ptr << ' ';
    // for (int i = 0; i < ptr; i++)
    //     std::cout << S[i] << ' ';

    long long ans = 0;
    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            int x = 0, y = 0;
            for (int i = l; i <= r; i++)
            {
                if (S[i]) y++;
                else x++;
                // std::cout << "si " << S[i] << '\n';
            }
            y = ptr - x;

            if (x > 0 && y > 0) ans += (x * y) % mod;
            else ans += ((x * x) % mod + (y * y) % mod) % mod;
            std::cout << x << ' ' << y << '\n';
        }
    }
    std::cout << ans;
}