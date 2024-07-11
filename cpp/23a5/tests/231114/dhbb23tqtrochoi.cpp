#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

long long q;
long long a;

const int N = 1e6 + 5;
int minPrime[N];
void minprime()
{
    for (int i = 2; i * i < N; i++)
        if (minPrime[i] == 0) for (int j = i * i; j < N; j += i)
            if (minPrime[j] == 0) minPrime[j] = i;
    for (int i = 2; i < N; i++)
        if (minPrime[i] == 0) minPrime[i] = i;
}

void sub123()
{
    minprime();
    while (q--)
    {
        int a; cin >> a;

        map<int, int> f;
        while (a > 1) f[minPrime[a]]++, a /= minPrime[a];

        long long ans = 1;
        for (auto &[p, a] : f) ans *= (pow(p, a + 1) - 1) / (p - 1);

        cout << ans << ' ';
    }
}

long long check(long long n)
{
    long long tong=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i!=i)tong+=n/i;
            tong+=i;
        }
    }
    return tong;
}
long long uoc[N];
void sub4()
{
    long long phu=0;
    for(int i=phu+1;i<=q+phu;i++)
    {
        cin>>a;
    }
    long long R=a;
    long long L=R-q+1;
    //cout<<L<<" "<<R<<'\n';
    for (long long i = 2; i * i <= R; ++i)
    {
        //cout<<endl<<i<<endl;
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        {
            //cout<<j<<" ";
            if(j/i!=i)uoc[j-L+1]+=j/i;
            uoc[j-L+1]+=i;
        }
    }
    for(long long i=L;i<=R;i++)
        cout<<uoc[i-L+1]+i+1<<' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>q;
    if (q <= 100000) sub123();
    else sub4();
}
