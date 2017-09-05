#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
long long ppow(long long a,long long n,long long mod)
{
	long long res=1;
	while(n>0)
	{
		if(n&1) res=(res*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	long long n,k;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("%lld\n",1+2*k);
		else
		{
			long long sum=ppow(2,n-2,1000000007);
			long long ans=ppow(2,n-3,1000000007);
			ans=(6*ans)%1000000007;
			ans=k*(ans-1)%1000000007;
			printf("%lld\n",(sum+ans)%1000000007);
		}		
	}
	return 0;
}
