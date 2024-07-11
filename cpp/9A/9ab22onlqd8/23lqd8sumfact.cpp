#include <iostream>

#define int long long

int dem(int n)
{
	long x,y,d,m;
	n=n*2;
	m=sqrt(n);

	d=0;
	for(long x=2;x<=m;x++)
	if(n%x==0)
	{
		y=n/x;
		if ((y-x)%2!=0)d++;
	}
	return d;
}

signed main()
{
    int n, m;
    std::cin >> n >> m;
    int f[n+1] = {};
    f[2] = ;
}