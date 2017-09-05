#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long qpow(long long  a,long long  b,long long  M)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return ans;
}
int main()
{
	long long t,a,b,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&m);
		long long tot=1;
		while(true)
		{
			long long ans=qpow(tot,a,m);
			if(ans==b)
				break;
			else
				tot++;		
		}
		printf("%lld\n",tot);
	}
	return 0;
}
