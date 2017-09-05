#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000005];
#define Max 2*1e18;
long long mx(long long x,long long y)
{
	if(x>=y)
		return x;
	else
		return y;
}
int main()
{
	long long t,n,ca=0;
	scanf("%lld",&t);
	while(t--)
	{
		ca++;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=2;i<=n;i++)
			a[i]+=a[i-1];
		long long maxx=0,x=100000000,minx=-Max;
		long long y=-Max;
		for(int i=1;i<=n;i++)
		{
			long long sum;
			if(a[i]>=0) sum=a[i];
			else sum=-a[i];
			if(sum%2==0)
			{
				if(a[i]<maxx)
					maxx=a[i];
				if(a[i]-x>y&&x!=0)
					y=a[i]-x;
			}
			else if(sum%2==1)
			{
				if(a[i]-maxx>minx)
					minx=a[i]-maxx;
				if(a[i]<x)
					x=a[i];
			}
		}
		printf("Case #%lld:\n%lld\n",ca,mx(minx,y));	
	}	
	return 0;
}
